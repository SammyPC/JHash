/**
 *  This is a program that is designed to run some tests on hash functions, it can generate the CCP ID numbers in the
 *  format "J12345678" and will run them though a hash function of choosing, counting up relevant stats and printing a
 *  report at the end.
 */


#include<iostream>
#include<random>
#include<string>
#include<cmath>


using namespace std;

/*
 * This is the original Basic Hash Function as given
 */
int hashFunction1(string key, int size) {
    int hash = 0;
    for(int i = 0; i < key.length(); i++) {
        hash = hash + key[i];
    }
    return hash % size;
}

/*
 * My function is super simple, it takes the strin, and then rips of the J to make an INT!
 * Hashing this value has a much higher amount for randomization
 */
int hashFunction2(string key, int size) {
    key.erase(key.begin()+0); // Mutates String to rip off the J
    int ID = stoi(key), hash;
    hash = ID % size; // simple hash on values as INT
    return hash;
}


/*
 * This will generate the J numbers to be sorted by the hash function! It has a few layers of random in there and
 * takes advantage of a function to even out the distribution of numbers generated.
 * (This helps the new hash function out dramatically)
 */
string jNumGen(){
    string jNum = "J";    // Init the String with the universal almighty all powerful starting J
    random_device seed;      // Init a single random device for a seed
    mt19937 gen(seed()); // Drop that seed into a mt19937 randomizer
    // Pass that to the uniform distro Gen to force the distribution curve of the numbers to spread out
    // and limit them to values in the range of eight digits
    uniform_int_distribution<int> range(10000000, 99999999);
    // Converts the int generated to a String and appends it to the jNum string after the almighty, all powerful starting J
    return jNum + to_string(range(gen));
}


/*
 * This allows you to easily set the size and number of items to generate and simulate sorting on
 * Rather than clean the first array this one stores the results for the second hash attempt in a second array
 */
void hashTestJNumbers() {
    constexpr int ARRAYSIZE = 27000, TOTALIDS = 25000;
    int a[ARRAYSIZE] = {};
    int b[ARRAYSIZE] = {};
    int collisionTotal = 0;
    int successfulHashes = 0;
    cout << "Testing Hash Function 1" << endl;
    for(int b = 0; b < TOTALIDS; b++){
       int h = hashFunction1(jNumGen(), ARRAYSIZE);
       a[h]++;
    }


    // Can comment out below when testing larger sizes!!
    for(int b = 0; b < ARRAYSIZE; b++) { // Show index and number of hashes to its position
        cout << "index " << b << " count = " << a[b] << endl;
    }
    // Can comment above out when testing larger sizes!!


    for(int b = 0; b < ARRAYSIZE; b++) {
        if (a[b] > 1) {
            collisionTotal += (a[b] - 1);
        } else if (a[b] == 1){
            successfulHashes++;
        }
    }
    cout << "The total Collision count is: " << collisionTotal << endl;
    cout << "The total count of successful hashes was:  " << successfulHashes << endl;
    cout << endl;

    // Reset values
    collisionTotal = 0;
    successfulHashes = 0;

    cout << "Testing Hash Function 2" << endl;
    for(int c = 0; c < TOTALIDS; c++){
        int h = hashFunction2(jNumGen(), ARRAYSIZE);
        b[h]++;
    }


    // Can comment out below when testing larger sizes
    for(int c = 0; c < ARRAYSIZE; c++) { // Show index and number of hashes to its position
        cout << "index " << c << " count = " << b[c] << endl;
    }
    // Can comment above out when testing larger sizes


    for(int c = 0; c < ARRAYSIZE; c++) {
        if (b[c] > 1) {
            collisionTotal += b[c];
        } else if (b[c] == 1){
            successfulHashes++;
        }
    }
    cout << "The total Collision count is: " << collisionTotal << endl;
    cout << "The total count of successful hashes was:  " << successfulHashes << endl;
}

int main() {
    hashTestJNumbers();
}
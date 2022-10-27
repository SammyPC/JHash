/**
 *  TODO Header
 */


#include<iostream>
#include<random>
#include<string>
#include<cmath>


using namespace std;


//Calculates a hash value for a string
int hashFunction1(string key, int size) {
    int hash = 0;
    for(int i = 0; i < key.length(); i++) {
        hash = hash + key[i];
    }
    return hash % size;
}
// TODO Change to chopping off the J and hashing based on the cast int left behind
int hashFunction2(string key, int size) {
    long sum = 0;
    long mul = 1;
    for (int i = 1; i < key.length(); i++) {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += key[i] * mul;
    }
    return (int)(abs(sum) % size);
}

int hashFunction3(string key, int size) {
    key.erase(0);
    int ID = stoi(key), hash;
    int c = ;
    for(int i = 0; i < key.length(); i++) {
        hash = floor (size * (ID * c % 1));
        }
    return hash;
}

int hashFunction4(string key, int size) {
    key.erase(0);
    int ID = stoi(key), hash;
    hash = ID % size;
    return hash;
}

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

//Keys generated: 03, 13, 23 ... 183, 193
//Array size: 10
void hashTestJNumbers100_127() {
    constexpr int ARRAYSIZE = 27000, TOTALIDS = 25000;
    int a[ARRAYSIZE] = {};
    int collisionTotal = 0;
    int successfulHashes = 0;
    int bigBucket = 0;
    int average = collisionTotal/ARRAYSIZE;
    cout << "Testing Hash Function 1";
    for(int b = 0; b < TOTALIDS; b++){
       int h = hashFunction1(jNumGen(), ARRAYSIZE);
       a[h]++;
    }
    for(int b = 0; b < ARRAYSIZE; b++) { // Show index and number of hashes to its position
        cout << "index " << b << " count = " << a[b] << endl;
    }
    for(int b = 0; b < ARRAYSIZE; b++) { // Show index and number of hashes to its position
        if (a[b] > 1) {
            collisionTotal += a[b];
        } else if (a[b] == 1){
            successfulHashes++;
        } else if (a[b] > bigBucket) {
            bigBucket = a[b];
        } else if (a[b] < average) {
           // use average to tell if value is high if so start count of index
           // store lowest index at start
           // store the final index at the end
           // subtract index at end of streak from beginning to get index length
           // show length, start index, end index
        }
    }
    cout << "The total Collision count is: " << collisionTotal << endl;
    cout << "The total count of successful hashes was:  " << successfulHashes << endl;
    cout << "The largest amount of hashes attempted to map at one index was: " << bigBucket << endl;
    cout << endl;


    cout << "Testing Hash Function 2" << endl;
    for(int b = 0; b < TOTALIDS; b++){
        int h = hashFunction2(jNumGen(), ARRAYSIZE);
        a[h]++;
    }
    for(int b = 0; b < ARRAYSIZE; b++) {
        cout << "index " << b << " count = " << a[b] << endl;
    }
    for(int b = 0; b < ARRAYSIZE; b++) { // Show index and number of hashes to its position
        if (a[b] > 1) {
            collisionTotal += a[b];
        } else if (a[b] == 1){
            successfulHashes++;
        } else if (a[b] > bigBucket) {
            bigBucket = a[b];
        } else if (a[b] < average) {
            // use average to tell if value is high if so start count of index
            // store lowest index at start
            // store the final index at the end
            // subtract index at end of streak from beginning to get index length
            // show length, start index, end index
        }
    }
    cout << "The total Collision count is: " << collisionTotal << endl;
    cout << "The total count of successful hashes was:  " << successfulHashes << endl;
    cout << "The largest amount of hashes attempted to map at one index was: " << bigBucket << endl;
}

int main() {
    hashTestJNumbers100_127();
    cout << endl ;

}
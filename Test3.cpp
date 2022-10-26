/**
 *  Demonstrates how keys are distributed with hash functions.
 *  In these examples, all of the keys will be strings. 
 *  The program simply adds one at the index of the hashed key.
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

int hashFunction2(string key, int size) {
    long sum = 0;
    long mul = 1;
    for (int i = 1; i < key.length(); i++) {
        mul = (i % 4 == 0) ? 1 : mul * 256;
        sum += key[i] * mul;
    }
    return (int)(abs(sum) % size);
}

string jNumGen(){
    string jNum = "J";    // Init a String with the universal almighty all powerful starting J
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
    cout << "Testing Hash Function 1";
    for(int b = 0; b < TOTALIDS; b++){
       int h = hashFunction1(jNumGen(), ARRAYSIZE);
       a[h]++;
    }
    for(int b = 0; b < ARRAYSIZE; b++) {
        cout << "index " << b << " count = " << a[b] << endl;
    }
    cout << endl;
    cout << "Testing Hash Function 2" << endl;
    for(int b = 0; b < TOTALIDS; b++){
        int h = hashFunction2(jNumGen(), ARRAYSIZE);
        a[h]++;
    }
    for(int b = 0; b < ARRAYSIZE; b++) {
        cout << "index " << b << " count = " << a[b] << endl;
    }
}

int main() {
    hashTestJNumbers100_127();
    cout << endl ;

}
/**
 *  Demonstrates how keys are distributed with hash functions.
 *  In these examples, they will be distributed evenly since there
 *  is one spot/index for every key. The program simply adds one at the index
 *  of the hashed key.
 */
#include<iostream>
#include<random>
#include<string>


using namespace std;
// Generator for the CCP ID Numbers
string jNumGenerator(){
    string jNum = "J";    // Init the String with the universal almighty all powerful starting J
    random_device seed;      // Init a single random device for a seed
    mt19937 gen(seed()); // Drop that seed into a mt19937 randomizer
    // Pass that to the uniform distro Gen to force the distribution curve of the numbers to spread out
    // and limit them to values in the range of eight digits
    uniform_int_distribution<int> range(10000000, 99999999);
    // Converts the int generated to a String and appends it to the jNum string after the almighty, all powerful starting J
    return jNum + to_string(range(gen));
}

//Keys generated in the for loop: 0-19
//Array size: 10
void hashTest1() {
    constexpr int size = 10; // set array size
    int a[size] = {0};

    for(int i = 0; i < 20; i++) {
        int hash = i % size;
        a[hash]++;
    }
    for(int i = 0; i < size; i++) {
        cout << "index " << i << " count = " << a[i] << endl;
    }

}

//Keys generated in the for loop: 0-19
//Array size: 20
void hashTest2() {
    constexpr int size = 20;
    int a[size] = {0};

    for(int i = 0; i < 20; i++) {
        int hash = i % size;
        a[hash]++;
    }
    for(int i = 0; i < size; i++) {
        cout << "index " << i << " count = " << a[i] << endl;
    }

}

int main() {
    hashTest1();
    cout << endl;
    hashTest2();
}

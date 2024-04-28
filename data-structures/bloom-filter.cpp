#include <bits/stdc++.h>
using namespace std;

class BloomFilter {
private:
    vector<bool> bitArray;
    int size;
    int numHashFunctions;

    int hashFunction(int num, int seed) {
        return (num * seed) % size;
    }

public:
    BloomFilter(int size, int numHashFunctions) {
        this->size = size;
        this->numHashFunctions = numHashFunctions;
        bitArray = vector<bool>(size, false);
    }

    void insert(int num) {
        for (int i = 0; i < numHashFunctions; i++) {
            int index = hashFunction(num, i);
            bitArray[index] = true;
        }
    }

    bool contains(int num) {
        for (int i = 0; i < numHashFunctions; i++) {
            int index = hashFunction(num, i);
            if (!bitArray[index]) {
                return false;
            }
        }
        return true;
    }

    void printBitArray() {
        for (int i = 0; i < bitArray.size(); i++) {
            cout<<bitArray[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    BloomFilter filter(10, 3);
    filter.insert(1);
    filter.insert(8);
    filter.insert(5);
    filter.printBitArray();

    for (int i = 0; i < 10; i++) {
        cout<<"contains("<<i<<") = "<<filter.contains(i)<<endl;
    }
}
#include <bits-stdc++.h>
using namespace std;

class UnorderedSet {
private:
    vector<list<int> > table;
    int size;

    int hash(int key) {
        return key % size;
    }
public:
    UnorderedSet() {
        size = 1000;
        table.resize(size);
    }
    
    void add(int key) {
        int idx = hash(key);
        list<int>& bucket = table[idx];
        for (int k : bucket) {
            if (k == key) {
                return;
            }
        }
        bucket.push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        list<int>& bucket = table[idx];
        bucket.remove(key);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        list<int>& bucket = table[idx];
        for (int k : bucket) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    UnorderedSet unSet;

    unSet.add(1);
    unSet.add(2);
    unSet.add(3);

    cout<<"Contains 1: "<<(unSet.contains(1) ? "True" : "False")<<endl; // True
    cout<<"Contains 2: "<<(unSet.contains(2) ? "True" : "False")<<endl; // True
    cout<<"Contains 3: "<<(unSet.contains(3) ? "True" : "False")<<endl; // True
    cout<<"Contains 4: "<<(unSet.contains(4) ? "True" : "False")<<endl; // False

    unSet.remove(2);
    cout<<"Contains 2: "<<(unSet.contains(2) ? "True" : "False")<<endl; // False

    unSet.add(2);
    cout<<"Contains 2: "<<(unSet.contains(2) ? "True" : "False")<<endl; // True

    return 0;
}

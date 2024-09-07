#include <bits-stdc++.h>
using namespace std;

class HashMap {
private:
    vector<list<pair<int, int> > > table;   // array of doubly linked list
    int size;                               // no of buckets

    int hash(int val) {
        return val % size;
    }
public:
    HashMap() {
        size = 1000;                        // higher number to reduce collision
        table.resize(size);
    }

    void put(int key, int val) {
        int idx = hash(key);
        list<pair<int, int> >& bucket = table[idx];
        for (auto& [k, v] : bucket) {
            if (k == key) {
                v = val;
                return;
            }
        }
        bucket.push_back(make_pair(key, val));
    }

    int get(int key) {
        int idx = hash(key);
        list<pair<int, int> >& bucket = table[idx];
        for (auto& [k, v] : bucket) {
            if (k == key) {
                return v;
            }
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        list<pair<int, int> >& bucket = table[idx];
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main() {
    HashMap hm;
    hm.put(1, 1);  // Add key = 1, value = 1
    hm.put(2, 2);  // Add key = 2, value = 2

    cout<<hm.get(1)<<endl;  // Should return 1 (key = 1 exists)
    cout<<hm.get(3)<<endl;  // Should return -1 (key = 3 does not exist)

    hm.put(2, 1);  // Update key = 2 to value = 1
    cout<<hm.get(2)<<endl;  // Should return 1 (key = 2 updated)

    hm.remove(2);  // Remove key = 2
    cout<<hm.get(2)<<endl;  // Should return -1 (key = 2 was removed)
    return 0;
}

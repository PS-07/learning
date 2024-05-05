#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    // store (val, idx)
    unordered_map<int, int> m;

    // store val at idx
    vector<int> v;
    int n;
public:
    RandomizedSet() {
        m.clear();
        n = 0;
    }

    // time complexity = O(1)
    bool insert(int val) {
        // if element is already in the set, return false
        if (m.find(val) != m.end()) { return false; }

        // else, update m and v, return true
        m[val] = n++;
        v.push_back(val);
        return true;
    }

    // time complexity = O(1)
    bool remove(int val) {
        // if element is not in the set, return false
        if (m.find(val) == m.end()) { return false; }

        // delete in O(1) from array
        // swap element with last element in v, remove last element from v, update m, return true
        int idx = m[val];
        v[idx] = v[n-1];
        m[v[n-1]] = idx;
        m.erase(val);
        v.pop_back();
        n--;
        return true;
    }

    // time complexity = O(1)
    int getRandom() {
        int idx = rand() % n;
        return v[idx];
    }
};

int main() {
    RandomizedSet rset;
    cout<<"rset.insert(1) = "<<rset.insert(1)<<endl;
    cout<<"rset.remove(2) = "<<rset.remove(2)<<endl;
    cout<<"rset.insert(2) = "<<rset.insert(2)<<endl;
    cout<<"rset.getRandom() = "<<rset.getRandom()<<endl;
    cout<<"rset.getRandom() = "<<rset.getRandom()<<endl;
    cout<<"rset.remove(1) = "<<rset.remove(1)<<endl;
    cout<<"rset.insert(2) = "<<rset.insert(2)<<endl;
    cout<<"rset.getRandom() = "<<rset.getRandom()<<endl;
    cout<<"rset.getRandom() = "<<rset.getRandom()<<endl;

    return 0;
}
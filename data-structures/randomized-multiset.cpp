#include <bits/stdc++.h>
using namespace std;

class RandomizedMultiSet {
private:
    // store (val, set(indexes))
    unordered_map<int, set<int>> m;

    // store val at idx
    vector<int> v;
    int n;

public:
    RandomizedMultiSet() {
        m.clear();
        n = 0;
    }

    // time complexity = O(1)
    bool insert(int val) {
        // if element is not in the multiset, insert and return true
        // if element is already in the multiset, insert again and return false
        if (m.find(val) == m.end()) { 
            m[val].insert(n++);
            v.push_back(val);
            return true; 
        } else {
            m[val].insert(n++);
            v.push_back(val);
            return false;
        }
    }

    // time complexity = O(1)
    bool remove(int val) {
        // if element is not in the multiset, return false
        if (m.find(val) == m.end()) {
            return false;
        }

        // delete in O(1) from array
        // if element is in the multiset, get largest index for the element
        // swap element with last element in v, remove last element from v, update m, return true
        set<int> &s1 = m[val];
        int idx = *s1.rbegin();

        if (idx == n - 1) {
            s1.erase(idx);
        } else {
            int last = v[n-1];
            set<int> &s2 = m[last];
            v[idx] = v[last];
            s1.erase(idx);
            s2.erase(*s2.rbegin());
            s2.insert(idx);
        }

        if (s1.size() == 0) {
            m.erase(val);
        }
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
    RandomizedMultiSet rmset;
    cout<<"rmset.insert(1) = "<<rmset.insert(1)<<endl;
    cout<<"rmset.insert(1) = "<<rmset.insert(1)<<endl;
    cout<<"rmset.insert(2) = "<<rmset.insert(2)<<endl;
    cout<<"rmset.insert(2) = "<<rmset.insert(2)<<endl;
    cout<<"rmset.insert(3) = "<<rmset.insert(3)<<endl;
    cout<<"rmset.insert(3) = "<<rmset.insert(3)<<endl;
    cout<<"rmset.getRandom() = "<<rmset.getRandom()<<endl;
    cout<<"rmset.getRandom() = "<<rmset.getRandom()<<endl;
    cout<<"rmset.remove(1) = "<<rmset.remove(1)<<endl;
    cout<<"rmset.remove(1) = "<<rmset.remove(1)<<endl;
    cout<<"rmset.getRandom() = "<<rmset.getRandom()<<endl;
    cout<<"rmset.getRandom() = "<<rmset.getRandom()<<endl;
    cout<<"rmset.remove(3) = "<<rmset.remove(3)<<endl;
    cout<<"rmset.remove(3) = "<<rmset.remove(3)<<endl;
    cout<<"rmset.getRandom() = "<<rmset.getRandom()<<endl;
    cout<<"rmset.getRandom() = "<<rmset.getRandom()<<endl;

    return 0;
}
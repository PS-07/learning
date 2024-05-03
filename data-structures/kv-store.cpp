#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class KvStore {
private:
    unordered_map<string, vector<pair<int, string > > > db;
public:
    KvStore() {
        db.clear();
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back(make_pair(timestamp, value));
    }

    void del(string key, int timestamp) {
        set(key, "", timestamp);
    }

    string get(string key, int timestamp) {
        vector<pair<int, string > > &values = db[key];
        string result = "";
        int l = 0;
        int r = values.size() - 1;
        int m;
        while (l <= r) {
            m = l + ((r - l) / 2);
            if (values[m].first <= timestamp) {
                result = values[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return result;
    }
};

int main() {
    KvStore kv;
    kv.set("k1", "v1", 1);
    kv.del("k1", 2);
    kv.set("k1", "v2", 4);
    
    cout<<"get(k1, 0) = "<<kv.get("k1", 0)<<endl;
    cout<<"get(k1, 2) = "<<kv.get("k1", 1)<<endl;
    cout<<"get(k1, 3) = "<<kv.get("k1", 3)<<endl;
    cout<<"get(k1, 5) = "<<kv.get("k1", 5)<<endl;
    
    return 0;
}

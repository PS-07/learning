#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
private:
    vector<map<int, int>> snap_arr;
    int n;
public:
    SnapshotArray(int len) {
        snap_arr.resize(len);
        for (auto &m : snap_arr) {
            m[0] = 0;
        }
        n = 0;
    }

    void set(int idx, int val) {
        snap_arr[idx][n] = val;
    }

    int snap() {
        return n++;
    }

    int get(int idx, int snap_id) {
        auto it = snap_arr[idx].upper_bound(snap_id);
        return prev(it)->second;
    }
};

int main() {
    cout<<"example 1"<<endl;
    SnapshotArray arr(2);
    arr.set(0, 5);
    arr.set(1, 3);
    arr.set(0, 6);

    int snap_id = arr.snap();
    cout<<"values at snapshot "<<snap_id<<":"<<endl;
    cout<<"index 0: "<<arr.get(0, snap_id)<<endl;
    cout<<"index 1: "<<arr.get(1, snap_id)<<endl;

    arr.set(0, 2);
    arr.set(1, 8);

    snap_id = arr.snap();
    cout<<"values at snapshot "<<snap_id<<":"<<endl;
    cout<<"index 0: "<<arr.get(0, snap_id)<<endl;
    cout<<"index 1: "<<arr.get(1, snap_id)<<endl;

    cout<<endl<<"example 2"<<endl;
    SnapshotArray arr1(1);
    arr1.set(0, 3);
    arr1.snap();
    arr1.snap();
    arr1.snap();
    arr1.snap();
    cout<<"values at snapshot 2: "<<endl;
    cout<<"index 0: "<<arr1.get(0, 2)<<endl;

    return 0;
}
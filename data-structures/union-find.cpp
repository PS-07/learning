#include <bits/stdc++.h>
using namespace std;

class UF {
private: 
    int size;
    vector<int> parent;
public:
    UF(int n) {
        size = n;
        parent = vector<int>(size, -1);
    }
    
    int ds_find(int x) {
        if(parent[x] < 0)
            return x;
        return parent[x] = ds_find(parent[x]);
    }
    
    void ds_union(int x, int y) {
        int par_x = ds_find(x);
        int par_y = ds_find(y);

        if(par_x == par_y)
            return ;

        int val_x = parent[par_x];
        int val_y = parent[par_y];
        
        if(val_x <= val_y) {
            parent[par_y] = par_x;
            parent[par_x] = -1 * (abs(val_x) + abs(val_y));
        }
        else {
            parent[par_x] = par_y;
            parent[par_y] = -1 * (abs(val_x) + abs(val_y));
        }
    }

    int no_of_ds() {
        int c = 0;
        for(int i=0; i<size; i++) {
            if(parent[i] < 0)
                c++;
        }
        return c;
    }
    
    int largest_ds() {
        int ans = INT_MAX;
        for(int i=0; i<size; i++) {
            if(parent[i] < ans)
                ans = parent[i];
        }
        return ans;
    }
    
    void print_parent() {
        for(int i=0; i<size; i++)
            cout<<parent[i]<<" ";
        cout<<endl;
    }
    
};
#include <bits/stdc++.h>
using namespace std;

void dfs_recursive(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    cout<<node<<" ";
    for (int neighbour : adj[node]) {
        if (!vis[neighbour]) 
            dfs_recursive(neighbour, adj, vis);
    }
}

void dfs_iterative(int node, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    stack<int> st;

    st.push(node);
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (!vis[curr]) {
            vis[curr] = true;
            cout<<curr<<" ";
            for (int i = adj[curr].size() - 1; i >= 0; i--) {
                int neighbour = adj[curr][i];
                if (!vis[neighbour])
                    st.push(neighbour);
            }
        }
    }
}

int main() {
    int n = 7;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1, 6};
    adj[5] = {2};
    adj[6] = {4};

    cout<<"Recursive DFS: ";
    vector<bool> vis(n, false);
    dfs_recursive(0, adj, vis);
    cout << endl;

    cout << "Iterative DFS: ";
    dfs_iterative(0, adj);
    cout << endl;
}
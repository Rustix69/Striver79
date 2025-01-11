#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool detect(int start, vector<vector<int>>& adj, int vis[]){
        vis[start] = 1;
        queue<pair<int,int>> q;
        q.push({start,-1});
        
        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto it : adj[node]){
                if(!vis[it]){
                    vis[it] =1;
                    q.push({it,node});
                }else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    
    
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        int vis[V] = {0};
        for (int i =0; i<V;i++){
            if(!vis[i]){
                if(detect(i, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
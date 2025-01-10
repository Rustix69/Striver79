#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid ){
        vis[row][col] = 2;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row1 = q.front().first;
            int col1 = q.front().second;
            q.pop();
            for (int delrow = -1; delrow<=1 ; delrow++){
                for (int delcol = -1; delcol<=1; delcol++){
                    int nrow = row1 +delrow;
                    int ncol = col1 + delcol;
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
            }
            
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0 ;
        for (int row = 0; row<n; row++){
            for (int col = 0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt ++ ;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
cout << "~" << "\n";
}
    return 0;
}

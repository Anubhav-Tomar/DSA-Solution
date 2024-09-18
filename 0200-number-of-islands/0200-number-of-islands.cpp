class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {1,0,-1,0};
            int delcol[] = {0,-1,0,1};

            for(int i=0; i<4; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                grid[row][col] == '1' && !vis[newrow][newcol]){
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};
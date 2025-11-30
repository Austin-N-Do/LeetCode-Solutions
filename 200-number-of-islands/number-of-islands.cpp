class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base cases: out of bounds or water or already visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        // Mark current cell as visited by changing it to '0'
        grid[i][j] = '0';
        
        // Explore all 4 directions
        dfs(grid, i + 1, j);  // down
        dfs(grid, i - 1, j);  // up
        dfs(grid, i, j + 1);  // right
        dfs(grid, i, j - 1);  // left
    }
};
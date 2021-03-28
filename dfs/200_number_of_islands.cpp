class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        // iterating through given grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                res+= dfs(grid, i, j);
            }
        }
        
        return res;
    }
    
    int dfs(vector<vector<char>>& grid, int i, int j) {
        // if out of bounds or at a cell with '0' or '#', simply stop and 
        // return 0 to end  dfs
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
            return 0;
        
        // start a group and visit all members of this group using dfs
        if (grid[i][j] == '1') {
            // destroying visited cells so they are not re-visited
            grid[i][j] = '#';  
            // recursive dfs on all neighbours
            dfs(grid, i + 1, j);
            dfs(grid, i - 1, j);
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
            return 1;
        }
        
        return 0;
    }
};

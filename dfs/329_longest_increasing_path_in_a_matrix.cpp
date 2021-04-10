class Solution {
public:
    int DFS(vector<vector<int>>& matrix, int row, int column, int val, vector<vector<int>>& memo)
    {
        if(row < 0 || row >= matrix.size() || column <0 || column >= matrix[0].size())
            return 0;
        if(matrix[row][column] > val)
        {
            if(memo[row][column] != 0) return memo[row][column];
            int a = DFS(matrix, row, column+1,matrix[row][column], memo) + 1;
            int b = DFS(matrix, row, column-1,matrix[row][column], memo) + 1;
            int c = DFS(matrix, row+1, column,matrix[row][column], memo) + 1;
            int d = DFS(matrix, row-1, column,matrix[row][column], memo) + 1;
            memo[row][column] = max(a, max(b,max(c, d)));
            return memo[row][column];
        }
        return 0;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        int res = 0;
        vector<int> temp(matrix[0].size(),0);
        vector<vector<int>> memo(matrix.size(), temp);
        for(int i = 0; i< matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                res = max(DFS(matrix, i, j, INT_MIN, memo), res);
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << memo[i][j] << ' ';
            }
            cout << endl;
        }
        
        return res;
    }
};

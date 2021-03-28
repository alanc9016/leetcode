class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        
        solveBoard(solutions, board, 0, n);   
        return solutions;
    }
    
    void solveBoard(vector<vector<string>>& solutions, vector<string>& board, int col, int n){
        if(col == n){
            solutions.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(validateSpot(board, row, col)){                
                
                board[row][col] = 'Q';
                solveBoard(solutions, board, col + 1, n);
                board[row][col] = '.';   
            
            }
        }        
    }
    
    bool validateSpot(vector<string>& board, int row, int col){
        int n = board.size(); 
        
        // check horizontally for queens in same row
        for(int x = 1; x <= col; x++){
            if(board[row][col-x] == 'Q') return false;
        }
        
        // check diagonals
        for(int x = 1; row-x >= 0 && col-x >= 0; x++){
            if(board[row-x][col-x] == 'Q') return false;
        }

        for(int x = 1; row+x < n && col-x >= 0; x++){
            if(board[row+x][col-x] == 'Q') return false;
        } 
        
        return true;
    }
};

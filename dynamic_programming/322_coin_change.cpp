class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < dp[0].size(); j++) {
                if(i == 0 && j < coins[i]) {
                    dp[0][j] = 100000;
                } else if(i == 0) {
                    dp[0][j] = 1 + dp[i][j - coins[i]];
                } else if(j < coins[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
                }
            }
        }
        
        return dp[n-1][amount] < 100000 ? dp[n-1][amount] : -1;
    }
};

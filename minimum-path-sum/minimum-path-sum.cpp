class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,INT_MAX));
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j] = grid[i][j];
                
                int next = min(dp[i+1][j], dp[i][j+1]);
                
                if(next != INT_MAX)
                    dp[i][j] += next;
            }
        }
        return dp[0][0];
    }
};
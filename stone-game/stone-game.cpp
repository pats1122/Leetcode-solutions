class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+3, vector<int>(n,0));
        
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                int temp = dp[i+2][j];
                if(j-1>=0)
                    temp = min(temp, dp[i+1][j-1]);
                dp[i][j] = piles[i] + temp;
                
                int temp1=0;
                if(j-1>=0)
                    temp1 = dp[i+1][j-1];
                if(j-2>=0)
                    temp1 = min(temp1, dp[i][j-2]);
                dp[i][j] = max(dp[i][j], temp1);
                
            }
        }
        return dp[0][n-1];
    }
};
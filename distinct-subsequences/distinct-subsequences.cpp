class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size(), i, j;
        long long mod = 1e10;
        vector<vector<long>> dp(n1+1, vector<long>(n2+1, 0));
        
        // Fill the first col with i
        for(i = 0; i <= n1; i++)
            dp[i][0] = 1;
        
        
        for(i = 1; i <= n1; i++){
            for(j = 1; j <= n2; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n1][n2];
    }
};
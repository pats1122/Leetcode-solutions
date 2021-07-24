class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), startId = n-1, maxLen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j<n; j++){
                
                if(s[i]!=s[j]){
                    dp[i][j] = false;
                }
                else{
                    if(j-1>=0)
                        dp[i][j] = dp[i+1][j-1];
                }
                
                if(dp[i][j]){
                    if(maxLen < j-i+1){
                        maxLen = j-i+1;
                        startId = i;
                }
                }
            }
        }
        return s.substr(startId, maxLen);
    }
};
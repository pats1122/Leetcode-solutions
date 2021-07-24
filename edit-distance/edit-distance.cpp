class Solution {
public:
    int minDistance(string word1, string word2) {
        int nA=word1.size(), nB=word2.size(), i, j;
        vector<vector<int>> dp(nA+1, vector<int>(nB+1));
        
        for(i=0; i<=nA; i++)
            dp[i][0] = i;
        for(j=0; j<=nB; j++)
            dp[0][j] = j;
        
        for(i=1; i<=nA; i++){
            for(j=1; j<=nB; j++){
                
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
                
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                else
                    dp[i][j] = min(dp[i][j],1+ dp[i-1][j-1]);
            }
        }
        return dp[nA][nB];
    }
};
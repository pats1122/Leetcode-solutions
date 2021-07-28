class Solution {
public:
    int func(string &s1, string &s2, string & s3, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i==s1.size() && j==s2.size()) return 1;
        
        //look-up
        if(dp[i][j] != -1) return dp[i][j];
        
        //recursive
        if(i<s1.size() && s1[i]==s3[i+j]){
            bool t = func(s1,s2,s3,i+1,j,dp);
            dp[i][j] = t;
            if(t)
                return true;
        }
        if(j<s2.size() && s2[j]==s3[i+j]){
            bool t = func(s1,s2,s3,i,j+1,dp);
            dp[i][j] = t;
            if(t)
                return true;
        }
        
        dp[i][j] = false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return func(s1, s2, s3, 0, 0, dp);
    }
};
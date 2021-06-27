class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1] = 0;
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j<n; j++){
                if(!isPalindrome(s,i,j))continue;
                
                if(j<n-1)
                     dp[i] = min(dp[i], 1+dp[j+1]);
                else
                    dp[i] =0;
            }
        }
        return dp[0];
    }
};
class Solution {
public:
    //s was not passed as reference so it gives error for large s
    bool isPalindrome(string &s){
        int lo=0, hi=s.size()-1;
        while(lo<hi){
            if(s[lo]!=s[hi]) return false;
            lo++;
            hi--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, INT_MAX);
        
        dp[n-1] = 0;
        for(int i=n-1; i>=0; i--){
            string curr = "";
            for(int j=i; j<n; j++){
                curr += s[j];
                
                if(isPalindrome(curr)){
                    if(j+1 != n)
                        dp[i] = min(dp[i], 1+dp[j+1]);
                    else
                        dp[i] = 0;
                }
            }
        }
        return dp[0];
    }
};
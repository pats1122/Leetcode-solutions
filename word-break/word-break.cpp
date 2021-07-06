class Solution {
public:
    int word(string A, unordered_map<string,int> &us, int start, vector<int> &dp){
        if(dp[start]!=-1) return dp[start];
        string t ="";
        for(int i=start; i<A.size(); i++){
            t += A[i];
            if(us[t]==1 ){
                int check = word(A,us,i+1,dp);
                if(check)
                    return dp[start] =  1;
            }
            
         }
        return dp[start]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> us;
        vector<int> dp(s.size()+1,-1);
        dp[s.size()] = 1;
        for(int i=0; i<wordDict.size(); i++){
            us[wordDict[i]]=1;
        }
        return word(s,us,0,dp);
    }
};
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        string w;
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[n]=true;
        
        for(int i=n-1;i>=0;i--){
            w="";
            for(int j=i;j<n;j++){
                w+=s[j];
                if(dict.find(w)!=dict.end() && dp[i+w.size()]){
                    dp[i]=true;
                    break;
                }
            }
            
        }
        return dp[0];
    }
};
*/
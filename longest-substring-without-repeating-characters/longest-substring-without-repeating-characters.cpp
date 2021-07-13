class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int res=0, l=0, r=0;
        
        while(r<s.size()){
            if(last[s[r]] != -1)
                l = max(l, last[s[r]]+1);
            
            last[s[r]] = r;
            
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
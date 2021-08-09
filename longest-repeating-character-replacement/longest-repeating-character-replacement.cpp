class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int res = INT_MIN;
        int left=0,right=0;
        
        while(right < s.size()){
             freq[s[right]-'A']++;
             right++; 
            
             int freq_of_max = *max_element(freq.begin(), freq.end());
             if(right-left-freq_of_max > k){
                freq[s[left]-'A']--;
                left++;
             }
            res = max(res, right-left);
        }
        return res;
    }
};
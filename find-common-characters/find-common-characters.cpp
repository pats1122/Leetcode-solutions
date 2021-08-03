class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size(), count;
        vector<vector<int>> freq(n, vector<int>(26,0));
        vector<string> res;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                char c = words[i][j];
                freq[i][c-'a']++;
            }
        }
        
        for(int i=0; i<26; i++){
            count=INT_MAX;
            for(int j=0; j<n; j++){
                count = min(count, freq[j][i]);
            }
            while(count){
                res.push_back(string(1,'a'+i));
                count--;
            }
        }
        return res;
    }
};
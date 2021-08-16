class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void part(string &s, int start, vector<string> curr, vector<vector<string>> &res){
        if(start==s.size()){
            res.push_back(curr);
            return;
        }
        
        for(int i= start; i<s.size(); i++){
            if(!isPalindrome(s,start,i)) continue;
            
            curr.push_back(s.substr(start,i-start+1));
            part(s,i+1,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        part(s,0,curr,res);
        return res;
    }
};
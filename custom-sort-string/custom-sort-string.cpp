class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,-1);
        for(int i=0; i<order.size(); i++)
            freq[order[i]-'a'] = i;
        
        sort(s.begin(),s.end(),[freq](char &a, char &b){
            //if(freq[a-'a']==freq[b-'a']) return a<b;
            return freq[a-'a']<freq[b-'a'];
        });
        return s;
    }
};
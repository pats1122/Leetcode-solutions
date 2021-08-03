vector<int> freq(256,0);
bool compare(char &a, char &b){
        if(freq[a]==freq[b]) return a<b;
        return freq[a]>freq[b];
    }
class Solution {
public:
    string frequencySort(string s) {
        fill(freq.begin(),freq.end(),0);
        for(int i=0; i<s.size(); i++)
            freq[s[i]]++;
        
        sort(s.begin(), s.end(), compare);
        return s;
    }
};
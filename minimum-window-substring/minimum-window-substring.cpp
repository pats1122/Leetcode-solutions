class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0) return "";
        
        //storing freq of allchar of t
        vector<int> freq(128,0);
        int required = t.size();
        for(auto c: t)
            freq[c]++;
        
        //sliding window
        int left=0, right=0;
        //size of smallest substring window
        int minSize=INT_MAX, start=0;
        
        //condition is right<=s.size() to ensure that even if we 
        //reach end of s, we are able to find
        //minimum substring window by moving left
        while(right<=s.size()){
            //invalid window
            //some characters of t are remaining to be satisfied by s
            if(required>0){
                //if req>0 and we have reached end
                if(right==s.size()) break;
                freq[s[right]]--;
                if(freq[s[right]]>=0) required--;
                right++;
            }
            //valid window
            else{
                //update minimum substring window
                if(minSize > right-left){
                    minSize = right-left;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0) required++;
                left++;
            }
        }
        return minSize==INT_MAX ? "":s.substr(start, minSize);
    }
};
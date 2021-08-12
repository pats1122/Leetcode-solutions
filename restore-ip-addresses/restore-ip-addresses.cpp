class Solution {
public:
    void restore(string &s, int start, vector<string> curr, vector<string> &res){
        int n = s.size();
        if(start==s.size() && curr.size()==4){
            string ip="";
            for(auto c: curr) ip+= c;
            ip.pop_back();
            res.push_back(ip);
            return;
        }
        if(start>=n || curr.size()>=4) return;
        
        //1 digit
            curr.push_back(s.substr(start,1) + ".");
            restore(s,start+1,curr,res);
             curr.pop_back();
        
            
        //2 digits
        if(stoi(s.substr(start,2))>=10 ){
            curr.push_back(s.substr(start,2) + ".");
            restore(s,start+2,curr,res);
            curr.pop_back();
        }
        
        //3 digits
        if(stoi(s.substr(start,3))>=100 && stoi(s.substr(start,3))<=255){
            curr.push_back(s.substr(start,3) + ".");
            restore(s,start+3,curr,res);
            curr.pop_back();
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> curr;
        vector<string> res;
        restore(s,0,curr,res);
        return res;
    }
};
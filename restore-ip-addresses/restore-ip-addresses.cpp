class Solution {
public:
    void restore(string &s, int start,vector<string> curr, vector<string> &res){
        if(start==s.size() && curr.size()==4){
            string ip = "";
            for(auto s:curr) ip+= s;
            ip.pop_back(); //to remove last "."
            res.push_back(ip);
            return;
        }
        
        if(start>=s.size() || curr.size()>=4)return;
        
        
        //1 digit
        curr.push_back(s.substr(start,1) + ".");
        restore(s,start+1,curr, res);
        curr.pop_back();

        
        //2 digit
        if(stoi(s.substr(start,2))>=10 ){
            curr.push_back(s.substr(start,2) + ".");
            restore(s,start+2,curr, res);
            curr.pop_back();
        }
        
        //3 digit
        if(stoi(s.substr(start,3))>=100 && stoi(s.substr(start,3))<256){
            curr.push_back(s.substr(start,3) + ".");
            restore(s,start+3,curr, res);
            curr.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12) return {};
        vector<string> res,curr;
        restore(s,0,curr,res);
        return res;
    }
};
class Solution {
public:
    string fractionToDecimal(int numerator_, int denominator_) {
        if(numerator_==0) return "0";
        string res="";
        //if num or den is negative
        if(numerator_<0 ^ denominator_<0) res += "-";
        
        //take absolute value of both
        long numerator = abs(numerator_);
        long denominator = abs(denominator_);
        
        //append interger part
        res += to_string(numerator/denominator);
        
        //no fractional part
        if(numerator%denominator == 0) return res;
        
        
        //fractional part
        //store position of all remainders
        //if any remainder is repeating, it is recurring
        res += ".";
        unordered_map<long,int> umap;
        long long rem = numerator%denominator;
        
        while(rem){
            //repeating remainder 
            if(umap.find(rem) != umap.end()){
                //insert "(" at umap[rem] index & ")" at last
                res.insert(umap[rem],"(");
                res += ")";
                break;
            }
            
            umap[rem] = res.size();
            rem *= 10;
            res += to_string(rem/denominator);
            rem = rem % denominator;
        }
        return res;
    }
};
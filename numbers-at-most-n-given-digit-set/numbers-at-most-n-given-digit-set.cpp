class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int cntN = floor(log10(n))+1, j;
        vector<int> dp(cntN+1, 0);
        
        vector<bool> isPresent(10, false);
        vector<int> count(10,0);
        for(int i=1; i<10; i++){
            for(j=0; j<digits.size()&& stoi(digits[j])<=i; j++){
                if((digits[j][0]-'0')==i) isPresent[i] = true;
                else count[i]++;
            }
        }
        
        // calculate count of numbers with digits = cntN
        dp[cntN] = 1;
        string N = to_string(n);
        for(int i=cntN-1; i>=0; i--){
            //less than 
            //kth digit is less than n%10
            dp[i] = count[N[i]-'0']*(pow(digits.size(), cntN-i-1));
                
            //equal
            //kth digit from last is equal
            if(isPresent[N[i]-'0'])
                dp[i] += dp[i+1];
            
        }
        int res = dp[0];
        
        //calculate the count of numbers < k digits
        //i is the number of digits
        for(int i=1; i<cntN; i++){
            res += pow(digits.size(), i);
        }
        return res;
    }
};
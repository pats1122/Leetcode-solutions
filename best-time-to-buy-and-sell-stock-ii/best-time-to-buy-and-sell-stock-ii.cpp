class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        
        dp1[0] = -prices[0];
        dp2[0] = 0;
        dp1[1] = max(dp1[0], -1*prices[1]);
        dp2[1] = max(0, prices[1]-prices[0]);
        
        for(int i=2; i<n; i++){
            dp1[i] = max(dp1[i-1], dp2[i-1]-prices[i]);
            dp2[i] = max(dp2[i-1], dp1[i-1]+prices[i]);
        }
        return dp2[n-1];
    }
};
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(),res=1;
        vector<vector<int>> dp(n,vector<int>(2,0));
        int par=1;
        
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j])
                    dp[i][1] = max(dp[i][1], max(2,1+dp[j][0]));
                else if(nums[i]<nums[j])
                    dp[i][0] = max(dp[i][0], max(2,1+dp[j][1]));
            }
            res = max(res,max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};
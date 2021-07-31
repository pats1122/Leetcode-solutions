class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum =0, x=0, n=nums.size();
        
        for(int i=0; i<(1<<n); i++){
            x=0;
            for(int j=0; j<n; j++){
                
                if((i&(1<<j)) != 0)
                    x = x^nums[j];
            }
            sum += x;
        }
        return sum;
    }
};
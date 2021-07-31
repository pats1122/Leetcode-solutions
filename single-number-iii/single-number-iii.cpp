class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x=0;
        int x1=0, x2=0;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++)
            x = x ^ nums[i];
        
        int last_set = x&(~(x-1));
        for(int i=0; i<nums.size(); i++){
            if((nums[i]&last_set )!= 0)
                x1 = x1^nums[i];
            else
                x2 = x2^nums[i];
        }
        return {x1,x2};
    }
};
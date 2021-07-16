class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0, len=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                len++;
                res = max(res, len);
            }
            else{
                len=0;
            }
        }
        return res;
    }
};
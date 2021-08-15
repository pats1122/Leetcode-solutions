class Solution {
public:
    void subset2(vector<int>& nums, int start,vector<int> curr, vector<vector<int>> &res){
        if(start==nums.size()){
            res.push_back(curr);
            return;
        }
        
        //exclude
        int i;
        for(i=start; i<nums.size()&& nums[i]==nums[start]; i++);
        subset2(nums,i, curr,res);
        
        //include
        curr.push_back(nums[start]);
        subset2(nums,start+1,curr,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        subset2(nums,0,curr,res);
        return res;
    }
};
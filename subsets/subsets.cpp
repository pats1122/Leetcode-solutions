class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //using bit manipulation
        int n = nums.size();
        vector<vector<int>> res;
        
        //traversing through 2^n(i.e 1<<n) subsets possible
        for(int i=0; i<(1<<n); i++){
            vector<int> temp;
            //traversing through 0 to n-1 elements of nums
            for(int j=0;j<n; j++){
                //if jth bit is set in ith subset, means jth element of arr 
                //is to be incuded in ith subset
                if((i&(1<<j))!=0)
                    temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
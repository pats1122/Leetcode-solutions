class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int len, res=0;
        for(int i=0; i<nums.size(); i++)
            us.insert(nums[i]);
        
        for(int i=0; i<nums.size(); i++){
            if(us.find(nums[i]-1)!=us.end()) continue;
            len = 1;
            while(us.find(nums[i]+len) != us.end())
                len++;
            res = max(res,len);
        }
        return res;
    }
};
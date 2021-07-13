class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()==0) return {};
        int left, right, n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; ){
            for(int j=i+1; j<n; ){
                left = j+1; 
                right = n-1;
                int target2 = target - nums[i] - nums[j];
                
                while(left < right){
                    if(nums[left] + nums[right] < target2) left++;
                
                    else if(nums[left]+nums[right] > target2) right--;
                    
                    else{
                       vector<int> temp(4); 
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        res.push_back(temp);
                        
                        while(left<right && nums[left]==temp[2]) left++;
                        while(left<right && nums[right]==temp[3]) right--;
                    }
                }
                int x = nums[j];
                 while(j<n && nums[j]==x)j++;
            } 
            int x = nums[i];
            while(i<n && nums[i]==x)i++;
        }
        return res;
    }
};
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo=0, hi=n-1, mid;
        
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            
            //target found
            if(nums[mid] == target) return true;
            
            //nums[lo]==nums[mid]==nums[hi]
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                lo++;
                hi--;
            }
            
            //left part is sorted
            else if(nums[lo]<=nums[mid]){
                //target is in range of left part
                if(nums[lo]<=target && nums[mid]>target) 
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            else{
                if(nums[mid]<target && nums[hi]>=target)
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        return false;
    }
};
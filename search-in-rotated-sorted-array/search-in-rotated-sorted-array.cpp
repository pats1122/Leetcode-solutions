class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo=0, hi=n-1, mid;
        
        while(lo<=hi){
            mid = (lo+hi)/2;
            //found target
            if(nums[mid]==target) return mid;
            
            //left part is sorted
            if(nums[lo]<=nums[mid]){
                //if target is in range of left part
                if(nums[lo]<=target && nums[mid]>target)
                    hi = mid-1;
                else
                    lo = mid+1;
            }
            //left part not sorted
            else{
                //target is in range of right part 
                if(nums[mid]<target && nums[hi]>=target)
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    void heapify(vector<int> &nums, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<n && nums[left]>nums[largest])
            largest = left;
        if(right<n && nums[right]>nums[largest])
            largest = right;
        
        if(largest != i){
            swap(nums[i], nums[largest]);
            heapify(nums,n,largest);
        }
            
    }
    vector<int> sortArray(vector<int>& nums) {
       //heap sort
        
        //build heap from array
        int n = nums.size();
        for(int i=n/2; i>=0; i--)
            heapify(nums, n, i);
        
        //swap max element with last element, call heapify for rest array
        for(int i=n-1; i>=0; i--){
            swap(nums[i],nums[0]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //counting sort
        //find max and min element 
        int min = *min_element(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        
        //declare freq array to keep frequency of each element
        vector<int> freq(max-min+1, 0);
        
        //store frequency of each element in range
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]-min]++;
        }
        
        //calculate prefix sum
        for(int i=1; i<freq.size(); i++)
            freq[i] += freq[i-1];
        
        //start putting elements at right pos from end
        vector<int> ans(nums.size());
        for(int i=nums.size()-1; i>=0; i--){
            int idx = freq[nums[i]-min] - 1 ;
            ans[idx] = nums[i];
            freq[nums[i]-min]--;
        }
        return ans;
    }
};
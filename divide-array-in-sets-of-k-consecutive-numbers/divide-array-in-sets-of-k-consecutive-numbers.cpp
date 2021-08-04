class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;
        
        map<int,int> freq;
        for(int i=0; i<n; i++)
            freq[nums[i]]++;
        
        for(auto it:freq){
            if(it.second>0){
                for(int j=0; j<k; j++){
                    if(freq[it.first + j] < it.second)
                        return false;
                    else
                        freq[it.first+j] -= it.second;
                }
            }
        }
            return true;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        int j,k;
        for(int i=0; i<n-2; i++){
            //nums[i] should be negative to make overall sum 0
            if(nums[i]>0) break;
            //if repeated number 
            if(i>0 && nums[i]==nums[i-1])continue;
            
            j=i+1, k=nums.size()-1;
            
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    int J=nums[j];
                    while(j<k && nums[j]==J)j++;
                    int K=nums[k];
                    while(j<k && nums[k]==K)k--;
                }  
                else if(nums[i]+nums[j]+nums[k]<0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};

/*
[]
[0,0]
[-2,-2,-2,1,1,1,1]
[0]
[-1,0,1,2,-1,-4]
*/
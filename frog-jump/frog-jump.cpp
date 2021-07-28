class Solution {
public:
    int find_idx(vector<int> &stones, int lo, int val){
        //binary search to find index of required val position of stone
        int hi = stones.size()-1, mid;
        //FF*TT*
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(stones[mid]<val)
                lo = mid +1;
            else
                hi = mid;
        }
        if(stones[lo] == val) return lo;
        return -1;
    }
    int func(int i, int k,vector<int> &stones, vector<vector<int>> &dp){
        //positive base case 
        if(i== stones.size()-1)
            return 1;
        
        //negative base case
        // nothing possible for 0 steps 
        if(k==0) 
            return 0;
        
        //dp look up
        if(dp[i][k] != -1) return dp[i][k];
        
        //recursively checking for k+1, k, k-1 steps 
        bool res = false;
        int j1, j2, j3 ;
        j1 = find_idx(stones, i, stones[i]+k+1);
        j2 = find_idx(stones, i, stones[i]+k);
        j3 = find_idx(stones, i, stones[i]+k-1);
        
        if(j1 != -1 ) res = res || func(j1,k+1,stones,dp);
        if(j2 != -1 ) res = res || func(j2,k,stones,dp);
        if(j3 != -1 ) res = res || func(j3,k-1,stones,dp);
        
        //storing and returning 
        return dp[i][k] = res;
    }
    
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        //not possile to go to 1st index from 0th index
        if(stones[1] - stones[0] > 1) return false;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        
        return func(1,1,stones,dp);
    }
};
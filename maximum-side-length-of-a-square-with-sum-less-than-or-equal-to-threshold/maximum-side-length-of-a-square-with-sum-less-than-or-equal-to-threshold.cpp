class Solution {
public:
    int get_sum(vector<vector<int>> &prefix, int len, int i, int j){
       int sum=0;
        sum = prefix[i][j];
        
        if(i-len>=0)
            sum -= prefix[i-len][j];
        if(j-len>=0)
            sum -= prefix[i][j-len];
        if(i-len>=0 && j-len>=0)
            sum += prefix[i-len][j-len];
        
        return sum;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n=mat[0].size();
        vector<vector<int>> prefix(m, vector<int>(n,0));
        int max_side = 0;
        
        //prefix sum array
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                prefix[i][j] = mat[i][j];
                if(i-1 >=0)
                    prefix[i][j] += prefix[i-1][j];
                if(j-1>=0)
                    prefix[i][j] += prefix[i][j-1];
                if(j-1>=0 && i-1>=0)
                    prefix[i][j] -= prefix[i-1][j-1];
                
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int lo=1, hi=min(i,j)+1, mid;
                //TT*FF*, last T
                while(lo<hi){
                   mid = lo+(hi-lo+1)/2;
                   if(get_sum(prefix,mid,i,j)<=threshold)
                       lo=mid;
                    else
                        hi=mid-1;
                }
                
                if(get_sum(prefix,lo,i,j)<=threshold)
                    max_side = max(max_side, lo);
            }
        }
        return max_side;
    }
};
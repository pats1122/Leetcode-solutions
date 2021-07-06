vector<vector<int>> dp(101, vector<int>(10001,-1));
class Solution {
public:
    
    int superEggDrop(int k, int n) {
        //base case
        //1 or 0 floor
        if(n==1 || n==0) return n;
        //1 egg
        if(k==1) return n;
        
        if(dp[k][n] != -1) return dp[k][n];
        //recursive
        int res = INT_MAX;
        int l=1, h=n, mid;
        while(l<=h){
            mid = (l+h)/2;
            int left = superEggDrop(k-1,mid-1);
            int right = superEggDrop(k,n-mid);
            //max(egg_breaks, egg_survives)
            res = min(res, 1+max(left, right));
            if(left < right){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return dp[k][n] = res;
    }
};
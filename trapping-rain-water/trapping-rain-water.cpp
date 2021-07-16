class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        vector<int> Rmax(n);
        
        Rmax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
            Rmax[i] = max(Rmax[i+1], height[i]);
        
        int water=0, Lmax=height[0];
        
        for(int i=1; i<n-1; i++){
            water += max(0, min(Lmax, Rmax[i])-height[i]);
            Lmax = max(Lmax, height[i]);
        }
        
        return water;
    }
};
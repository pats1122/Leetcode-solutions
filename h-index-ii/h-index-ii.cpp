class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(),lo=0, hi=n-1, mid;
        
        //FF*TT*
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(citations[mid] >= (n-mid))
                hi = mid;
            else
                lo = mid+1;
        }
        
        if(lo<n && citations[lo]>=n-lo)
            return n-lo;
        return 0;
    }
};
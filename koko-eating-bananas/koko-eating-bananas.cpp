class Solution {
public:
    int bananas(vector<int> &piles, int b){
        int hours =0;
        for(int i=0; i<piles.size(); i++){
            hours += ceil((double)piles[i]/b);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, hi=*max_element(piles.begin(), piles.end());
        int mid;

        //FF*TT*, first T
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(bananas(piles, mid) <= h)
                hi = mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};
class Solution {
public:
    int get_days(vector<int> &weights, int cap){
        int days = 1;
        int curr =0;
        for(int i=0; i<weights.size(); i++){
            if(curr + weights[i] <= cap)
                curr += weights[i];
            else{
                curr = weights[i];
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo , hi , mid, sum=0;
        lo = *max_element(weights.begin(), weights.end());
        hi = accumulate(weights.begin(), weights.end(), sum);
        
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(get_days(weights, mid) <= days)
                hi = mid;
            else
                lo = mid+1;
        }
        return lo;
    }
};
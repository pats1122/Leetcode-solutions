class Solution {
public:
    int get_sum(vector<int> &arr, int val){
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>=val)
                sum += val;
            else
                sum += arr[i];
        }
        return sum;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int lo=0, hi, mid;
        hi = *max_element(arr.begin(), arr.end());
        
        //FF*TT*, last F
        while(lo<hi){
            mid = lo+(hi-lo+1)/2;
            if(get_sum(arr,mid) >= target)
                hi = mid-1;
            else
                lo = mid;
        }
        int dif1 = abs(target - get_sum(arr,lo));
        int dif2 = abs(target - get_sum(arr,lo+1));
        
        if(dif2<dif1) return lo+1;
        else return lo;
    }
};
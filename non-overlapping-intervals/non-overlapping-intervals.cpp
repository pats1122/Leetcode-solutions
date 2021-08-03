bool compare(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
    // return a[0]<b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int cnt = 1;
        int last = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=last){
                cnt++;
                last = intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};
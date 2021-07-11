bool compare(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<int> temp;
        vector<vector<int>> res;
         sort(intervals.begin(), intervals.end(), compare);
         temp = intervals[0];
        
        for(int i=1; i<intervals.size(); i++){
            if(temp[1] >= intervals[i][0])
                temp[1] = max(temp[1], intervals[i][1]);
            else{
                res.push_back(temp);
                temp = intervals[i];
            }
        }
        res.push_back(temp);
        return res;
    }
};
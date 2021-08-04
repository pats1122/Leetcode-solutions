bool compare(vector<int> &a, vector<int> &b){
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]>b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> res(people.size());
        
        int i, j;
        for(i=0; i<people.size(); i++){
            for(j=i; j>people[i][1]; j--)
                res[j] = res[j-1];
            res[j] = people[i];
        }
        return res;
    }
};
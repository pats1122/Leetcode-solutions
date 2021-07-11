class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows>=1) res.push_back({1});
        if(numRows>=2) res.push_back({1,1});
        for(int i=3; i<=numRows; i++){
            vector<int> curr;
            curr.push_back({1});
            
            vector<int> prev = res[res.size()-1];
            for(int j=0; j<prev.size()-1; j++){
                curr.push_back(prev[j]+prev[j+1]);
            }
            curr.push_back(1);
            res.push_back(curr);
        }
        return res;
    }
};
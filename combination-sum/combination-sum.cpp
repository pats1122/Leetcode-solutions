class Solution {
public:
    void combination(vector<int> &candidates, int target, int start, vector<int> curr, vector<vector<int>> &res){
        if(start==candidates.size() && target==0){
            res.push_back(curr);
            return;
        }
        if(target<0 || start>=candidates.size()) return;
        
        //exclude
        combination(candidates,target,start+1,curr,res);
        
        //include
        curr.push_back(candidates[start]);
        combination(candidates,target-candidates[start], start, curr,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        combination(candidates, target, 0, curr, res);
        return res;
    }
};
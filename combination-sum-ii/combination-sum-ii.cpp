class Solution {
public:
     void combination(vector<int> &candidates, int target, int start, vector<int> curr, vector<vector<int>> &res){
        if(start==candidates.size() && target==0){
            res.push_back(curr);
            return;
        }
        if(target<0 || start>=candidates.size()) return;
        
        //exclude
         int i;
         for(i=start; i<candidates.size()&&candidates[i]==candidates[start];i++);
        combination(candidates,target,i,curr,res);
        
        //include
        curr.push_back(candidates[start]);
        combination(candidates,target-candidates[start], start+1, curr,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> curr;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combination(candidates, target, 0, curr, res);
        return res; 
    }
};
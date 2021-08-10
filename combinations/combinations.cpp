class Solution {
public:
    void combineHelper(int n, int k, int startIdx,int size, vector<int> curr, vector<vector<int>> &res){
     if(size==k){
        res.push_back(curr);
        return;
    }
        if(startIdx>n)
            return;
        if(n-startIdx+1 < k-size) return ;
        //exclude
        combineHelper(n,k,startIdx+1,size,curr,res);
        //include
        curr.push_back(startIdx);
        combineHelper(n,k,startIdx+1,size+1,curr,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        combineHelper(n,k,1,0,curr,res);
        return res;
    }
};
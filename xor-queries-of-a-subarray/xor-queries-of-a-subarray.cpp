class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), x;
        //xor prefix array 
        vector<int> xorp(n,0);
        vector<int> res;
        
        //computing prefix xor for all index
        xorp[0] = arr[0];
        for(int i=1; i<n; i++)
            xorp[i] = xorp[i-1] ^ arr[i];
        
        //xor[L-1] ^ xor [R] gives xor(L to R)
        //as xor[L-1] gets cancelled (a^a=0)
        for(int i=0; i<queries.size(); i++){
            //if L =0, return xor(R) else xor(L-1)^xor(R)
            x = queries[i][0]==0 ? 0 : xorp[queries[i][0]-1];
            x = x ^ xorp[queries[i][1]];
            res.push_back(x);
        }
        return res;
    }
};
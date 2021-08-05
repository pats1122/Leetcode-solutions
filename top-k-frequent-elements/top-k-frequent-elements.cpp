struct compare{
  bool operator()(vector<int> &a, vector<int> &b){
      if(a[0]==b[0]) return a[1]>b[1];
      return a[0] > b[0];
  }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>umap;
        
        for(int i=0; i<nums.size(); i++)
            umap[nums[i]]++;
        
        priority_queue<vector<int>, vector<vector<int>>, compare> minq;
        
        for(auto it: umap){
            if(minq.size()<k)
                minq.push({it.second, it.first});
            else{
                if(minq.top()[0] < it.second){
                    minq.pop();
                    minq.push({it.second, it.first});
                }
            }
        }
        vector<int> res;
        while(!minq.empty()){
            res.push_back(minq.top()[1]);
            minq.pop();
        }
        return res;
    }
};
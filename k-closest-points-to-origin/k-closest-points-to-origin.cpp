struct compare{
    bool operator()(vector<int> &a, vector<int> &b){
        return (a[0]*a[0]+a[1]*a[1]) < (b[0]*b[0]+b[1]*b[1]);
    }
};
class Solution {
public:
    int dist(vector<int> d){
        return d[0]*d[0] + d[1]*d[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> maxq;
        
        for(int i=0; i<points.size(); i++){
            if(maxq.size()<k)
                maxq.push(points[i]);
            else{
                vector<int> t = maxq.top();
                if(dist(t)>dist(points[i])){
                    maxq.pop();
                    maxq.push(points[i]);
                }
            }
        }
        vector<vector<int>> res;
        while(!maxq.empty()){
            res.push_back(maxq.top());
            maxq.pop();
        }
        return res;
    }
};
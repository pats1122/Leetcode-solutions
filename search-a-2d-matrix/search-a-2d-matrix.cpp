class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n=matrix[0].size();

        int lo=0, hi= m*n -1, mid;
        while(lo<hi){
            mid = lo+(hi-lo)/2;
            if(matrix[mid/n][mid%n] < target)
                lo=mid+1;
            else
                hi=mid;
        }
        return matrix[lo/n][lo%n]==target;
    }
};
//method 2
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();
        
        for(int i=0; i<n/2; i++){
            for(int j=i; j<n-i-1; j++){
                //store up in temp
                int temp = matrix[i][j];
                
                //left to up
                matrix[i][j] = matrix[n-1-j][i];
                //bottom to left
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                //right to bottom
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                //right - store up
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
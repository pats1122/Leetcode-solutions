class Solution {
public:
    bool isequal(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    bool clockwise(vector<vector<int>> mat, vector<vector<int>>& target,int &cnt){
        if(cnt==4) return false;
        int n= mat.size();
        //tranpose
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++)
                swap(mat[i][j], mat[j][i]);
        }
        
        //reverse rows
        for(int i=0; i<n; i++)
            reverse(mat[i].begin(), mat[i].end());
        
        if(isequal(mat,target)) return true;
        cnt++;
        return clockwise(mat,target,cnt) || anticlockwise(mat,target,cnt);
    }
    bool anticlockwise(vector<vector<int>> mat, vector<vector<int>>& target,int &cnt){
        if(cnt==4) return false;
        int n= mat.size();
       //tranpose
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++)
                swap(mat[i][j], mat[j][i]);
        }
        
        //reverse columns
        for(int i=0; i<n; i++){
            for(int j=0, k=n-1; j<k; j++, k--)
                swap(mat[j][i], mat[k][i]);
        }
            
        
        if(isequal(mat,target)) return true;
        cnt++;
        return clockwise(mat,target,cnt) || anticlockwise(mat,target,cnt);
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(isequal(mat,target)) return true;
        int cnt=0;
        return clockwise(mat,target,cnt)||anticlockwise(mat,target,cnt);
    }
};
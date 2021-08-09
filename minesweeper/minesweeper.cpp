class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{-1,-1},{1,-1}};
    
    //count of adjacent mines
    int NumAdjacentMines(vector<vector<char>>& board,int i, int j){
        int num=0;
        for(auto dir:dirs){
            int x = i+dir[0];
            int y = j+dir[1];
            if(x<0||x>=board.size()||y<0||y>=board[0].size()) continue;
            if(board[x][y]=='M') num++;
        }
        return num;
    }
    
    //dfs function
    void dfs(vector<vector<char>>& board,int i, int j){
        int m = board.size(), n=board[0].size();
        //out of boundary
        if(i<0 || i>=m || j<0 || j>=n) return;
        
        //already visited or M
        if(board[i][j] == 'B' || board[i][j]=='M'|| (board[i][j]>='1' && board[i][j]<='8')) return;
        
        //current cell is E
        int num = NumAdjacentMines(board,i,j);
        if(num==0){
            board[i][j] = 'B';
            //traverse all directions
            for(auto dir:dirs){
                dfs(board,i+dir[0], j+dir[1]);
             }
        }
        else{
            board[i][j] = '0'+num; 
        } 
    }
    
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            //game over, if click is on M
            if(board[click[0]][click[1]] == 'M'){
                board[click[0]][click[1]] = 'X';
                return board;
            }
        
            //click is on E
            else if(board[click[0]][click[1]] =='E'){
                int n = NumAdjacentMines(board,click[0],click[1]);
                //no adjacent mines, travel recursively
                if(n==0){
                    dfs(board,click[0],click[1]);
                }
                //has adjacent mines
                else{
                    board[click[0]][click[1]] = '0'+n; 
                }
            }
        
        return board;
    }
};
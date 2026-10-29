// Knight's Tour (Medium)
// https://www.geeksforgeeks.org/problems/the-knights-tour-problem/1
// Correct 2026-09-15 10:37:35 | C++

class Solution {
  public:
    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2};
    
    bool solve(int x, int y, int move, int n, vector<vector<int>> &board){
        if(move == n*n){
            return true;
        }
        
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >=n || ny < 0 || ny >= n || board[nx][ny]!=-1){
                continue;
            }
            
            board[nx][ny] = move;
            
            if(solve(nx,ny,move+1,n,board)){
                return true;
            }
            
            board[nx][ny] = -1;
        }
        
        return false;
    }
  
  
    vector<vector<int>> knightTour(int n) {
        // code here
        if(n<5 && n>1){
            return {};
        }
        if(n==1){
            return {{0}};
        }
        
        vector<vector<int>> board(n,vector<int>(n,-1));
        
        board[0][0] = 0;
        
        if(solve(0,0,1,n,board)){
            return board;
        }
        
        return {};
        
    }
};
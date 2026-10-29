// Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/
// Accepted 2026-07-02 | Runtime 0 ms | Memory 13.8 MB

class Solution {
public:

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    void dfs(int row, int col, vector<vector<char>>& board, int n, int m){
        if(row<0 || row >=n || col<0 || col>=m || board[row][col]!='O'){
            return;
        }
        board[row][col] = '#';
        for(int i=0;i<4;i++){
            dfs(row+dx[i],col+dy[i],board,n,m);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
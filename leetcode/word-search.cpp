// Word Search
// https://leetcode.com/problems/word-search/
// Accepted 2026-08-08 | Runtime 864 ms | Memory 11.6 MB

class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>>& board, string word, int x){
        if(x==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[x]!=board[i][j]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';

        if(dfs(i+1,j,board,word,x+1) || dfs(i-1,j,board,word,x+1) || dfs(i,j+1,board,word,x+1) || dfs(i,j-1,board,word,x+1)){
            return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }

        return false;
    }
};
// Rat in Maze (Medium)
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Correct 2026-10-14 17:59:22 | C++

class Solution {
  public:
    vector<string> res;
    
    void dfs(int i, int j, vector<vector<int>>& maze, string temp){
        if(i<0 || i>=maze.size() || j<0 || j>=maze[0].size() || maze[i][j]==0){
            return;
        }
        
        if(i==maze.size()-1 && j==maze[0].size()-1){
            res.push_back(temp);
            return;
        }
        
        maze[i][j] = 0;
        
        dfs(i+1,j,maze,temp+"D");
        dfs(i-1,j,maze,temp+"U");
        dfs(i,j+1,maze,temp+"R");
        dfs(i,j-1,maze,temp+"L");
        
        maze[i][j] = 1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        dfs(0,0,maze,"");
        sort(res.begin(), res.end());
        return res;
    }
};
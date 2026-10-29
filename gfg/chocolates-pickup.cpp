// Chocolates Pickup (Hard)
// https://www.geeksforgeeks.org/problems/chocolates-pickup/1
// Correct 2026-09-27 14:29:46 | C++

class Solution {
private:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // Boundary check
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

        // Base case: Last row
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        // Return memoized value if already computed
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e9;

        // Try all 9 possible moves for both robots (3 moves each)
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int chocolates = 0;
                if (j1 == j2) chocolates = grid[i][j1];
                else chocolates = grid[i][j1] + grid[i][j2];

                chocolates += solve(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
                maxi = max(maxi, chocolates);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

public:
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 3D DP table: dp[row][col_robot1][col_robot2]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m - 1, n, m, grid, dp);
    }
};

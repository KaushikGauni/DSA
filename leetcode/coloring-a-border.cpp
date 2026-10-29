// Coloring A Border
// https://leetcode.com/problems/coloring-a-border/
// Accepted 2026-10-11 | Runtime 0 ms | Memory 18.1 MB

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        int origColor = grid[row][col];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> borders;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        auto dfs = [&](auto& self, int r, int c) -> void {
            visited[r][c] = true;
            int validNeighbors = 0;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (visited[nr][nc]) {
                        validNeighbors++;
                    } else if (grid[nr][nc] == origColor) {
                        validNeighbors++;
                        self(self, nr, nc);
                    }
                }
            }

            if (validNeighbors < 4) {
                borders.push_back({r, c});
            }
        };

        dfs(dfs, row, col);

        for (auto& [r, c] : borders) {
            grid[r][c] = color;
        }

        return grid;
    }
};
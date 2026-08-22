class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        const int INF = 2147483647;

        queue<pair<int, int>> q;

        // Put all treasure cells (0) into the queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Multi-source BFS
        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check boundary
                if(nr < 0 || nr >= m ||
                   nc < 0 || nc >= n) {
                    continue;
                }

                // Only visit unvisited land cells
                if(grid[nr][nc] != INF) {
                    continue;
                }

                // Distance = current distance + 1
                grid[nr][nc] = grid[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};
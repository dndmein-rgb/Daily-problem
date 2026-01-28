class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int k,
              vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (i == n || j == m || k < 0) return 1e9;
        if (i == n - 1 && j == m - 1) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int path1 = 1e9, path2 = 1e9;

        if (i + 1 < n)
            path1 = grid[i + 1][j] + solve(i + 1, j, grid, k, dp);

        if (j + 1 < m)
            path2 = grid[i][j + 1] + solve(i, j + 1, grid, k, dp);

        int mini = 1e9;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if ((row == i && col == j) ||
                    grid[i][j] < grid[row][col])
                    continue;
                mini = min(mini, solve(row, col, grid, k - 1, dp));
            }
        }

        return dp[i][j][k] = min({mini, path1, path2});
    }

    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        return solve(0, 0, grid, k, dp);
    }
};

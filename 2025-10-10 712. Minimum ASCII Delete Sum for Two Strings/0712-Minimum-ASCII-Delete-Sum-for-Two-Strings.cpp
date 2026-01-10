/* Approach 1: Top-Down DP (Memoization)
   Time Complexity: O(N * M)
   Space Complexity: O(N * M)
*/
class Solution {
public:
    int t[1001][1001];
    
    int solve(string& s1, string& s2, int i, int j) {
        int n = s1.length(), m = s2.length();
        
        // Base Case: If s2 is exhausted, we must delete remaining s1
        if (j >= m) {
            int cost = 0;
            while (i < n) cost += s1[i++];
            return cost;
        }
        // Base Case: If s1 is exhausted, we must delete remaining s2
        if (i >= n) {
            int cost = 0;
            while (j < m) cost += s2[j++];
            return cost;
        }
        
        if (t[i][j] != -1) return t[i][j];

        if (s1[i] == s2[j]) {
            return t[i][j] = solve(s1, s2, i + 1, j + 1);
        } else {
            int del_s1 = s1[i] + solve(s1, s2, i + 1, j);
            int del_s2 = s2[j] + solve(s1, s2, i, j + 1);
            return t[i][j] = min(del_s1, del_s2);
        }
    }

    int minimumDeleteSum(string s1, string s2) { 
        memset(t, -1, sizeof(t));
        return solve(s1, s2, 0, 0); 
    }
};

/* Approach 2: Bottom-Up DP (Tabulation)
   Time Complexity: O(N * M)
   Space Complexity: O(N * M)
*/
class SolutionTab {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases: filling the last row and last column
        for (int j = m - 1; j >= 0; j--) dp[n][j] = dp[n][j + 1] + s2[j];
        for (int i = n - 1; i >= 0; i--) dp[i][m] = dp[i + 1][m] + s1[i];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(s1[i] + dp[i + 1][j], s2[j] + dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};

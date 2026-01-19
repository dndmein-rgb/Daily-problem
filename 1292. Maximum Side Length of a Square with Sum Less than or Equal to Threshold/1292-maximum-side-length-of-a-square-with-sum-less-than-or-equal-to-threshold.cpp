class Solution {
public:
    bool canBuild(int len, int i, int j, int threshold, vector<vector<int>>& pref) {
        int sum = pref[i + len - 1][j + len - 1]
                - pref[i - 1][j + len - 1]
                - pref[i + len - 1][j - 1]
                + pref[i - 1][j - 1];
        return sum <= threshold;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int low = ans + 1;
                int high = min(n - i + 1, m - j + 1);

                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (canBuild(mid, i, j, threshold, pref)) {
                        ans = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }
        return ans;
    }
};

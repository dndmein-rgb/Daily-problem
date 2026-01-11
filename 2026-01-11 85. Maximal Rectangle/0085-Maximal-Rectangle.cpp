/* Pattern: Monotonic Stack + Histogram DP
   Time Complexity: O(N * M) - Each cell is processed once per row.
   Space Complexity: O(M) - To store the current histogram heights.
*/

class Solution {
public:
    // Finds indices of next smaller elements to determine right boundaries
    vector<int> next(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmaller(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (!s.empty()) nextSmaller[i] = s.top();
            s.push(i);
        }
        return nextSmaller;
    }

    // Finds indices of previous smaller elements to determine left boundaries
    vector<int> prev(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            if (!s.empty()) prevSmaller[i] = s.top();
            s.push(i);
        }
        return prevSmaller;
    }

    // Standard "Largest Rectangle in Histogram" logic
    int max_area(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller = prev(heights);
        vector<int> nextSmaller = next(heights);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            maxi = max(maxi, width * heights[i]);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Update height: if '1' extend current height, if '0' reset to 0
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            // After processing each row, solve for that histogram
            maxi = max(maxi, max_area(heights));
        }
        return maxi;
    }
};

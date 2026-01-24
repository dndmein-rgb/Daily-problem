class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int interLeft   = max(bottomLeft[i][0], bottomLeft[j][0]);
                int interRight  = min(topRight[i][0],  topRight[j][0]);
                int interBottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int interTop    = min(topRight[i][1],  topRight[j][1]);

                long long width  = interRight - interLeft;
                long long height = interTop - interBottom;

                if (width > 0 && height > 0) {
                    long long side = min(width, height);
                    maxSide = max(maxSide, side);
                }
            }
        }
        return maxSide * maxSide;
    }
};

/* Pattern: Geometry / Math
   Time Complexity: O(N) - Single pass through the points array
   Space Complexity: O(1) - Constant extra space
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        int n = points.size();
        
        // Iterate through each consecutive pair of points
        for (int i = 0; i < n - 1; i++) {
            // The minimum time to travel between two points (x1, y1) and (x2, y2)
            // is the maximum of the absolute differences of their coordinates.
            // This is because we can move diagonally (1 unit in both x and y).
            int dx = abs(points[i][0] - points[i + 1][0]);
            int dy = abs(points[i][1] - points[i + 1][1]);
            
            time += max(dx, dy);
        }
        
        return time;
    }
};

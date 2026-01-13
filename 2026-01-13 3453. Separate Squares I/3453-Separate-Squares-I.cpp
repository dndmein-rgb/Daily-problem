/* Pattern: Binary Search on Answer
   Time Complexity: O(N * log(Range/Precision))
   Space Complexity: O(1)
*/

class Solution {
public:
    // Helper function to calculate area below the horizontal line mid_y
    bool check(vector<vector<int>>& squares, double mid_y, double total) {
        double bot_area = 0;

        for(auto &square : squares) {
            double y = square[1];
            double l = square[2];

            double boty = y;
            double topy = y + l;

            if (mid_y >= topy) {
                // Entire square is below mid_y
                bot_area += l * l;
            } else if (mid_y > boty) {
                // mid_y cuts through the square; add the partial area below
                bot_area += (mid_y - boty) * l;
            }
        }

        // We want the line where bot_area == top_area, which is bot_area == total/2
        return bot_area >= total / 2.0; 
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low   = 2e9; // Sufficiently high value
        double high  = -2e9;
        double total = 0.0;

        for(auto &square : squares) {
            double y = (double)square[1];
            double l = (double)square[2];
            total += l * l;

            low  = min(low, y);
            high = max(high, y + l);
        }

        double result_y = low;

        // Binary search for the y-coordinate with required precision
        for (int i = 0; i < 100; i++) { // Using iterations for precision reliability
            double mid_y = low + (high - low) / 2.0;
            
            if (check(squares, mid_y, total)) {
                // Area below is too large, move the line lower
                result_y = mid_y;
                high = mid_y;
            } else {
                // Area below is too small, move the line higher
                low = mid_y;
            }
        }

        return result_y;
    }
};

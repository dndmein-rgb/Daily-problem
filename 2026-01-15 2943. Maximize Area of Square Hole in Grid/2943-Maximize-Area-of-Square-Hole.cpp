class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxConsecutiveH = 1, maxConsecutiveV = 1;

        int currH = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                currH++;
                maxConsecutiveH = max(maxConsecutiveH, currH);
            } else {
                currH = 1;
            }
        }

        int currV = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                currV++;
                maxConsecutiveV = max(maxConsecutiveV, currV);
            } else {
                currV = 1;
            }
        }

        int side = 1 + min(maxConsecutiveH, maxConsecutiveV);
        return side * side;
    }
};

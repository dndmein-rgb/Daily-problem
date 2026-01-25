#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Sort + Sliding Window (Clean & Optimal)
Time: O(n log n)
Space: O(1)
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX;

        for (int i = 0; i + k - 1 < n; i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }

        return minDiff;
    }
};

/*
Approach 2: Reverse Sort + Two Pointer Window
Time: O(n log n)
Space: O(1)

Included for learning comparison.
More verbose, same idea, slightly worse readability.
*/
class SolutionAlt {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int minDiff = INT_MAX;

        int i = 0, j = 0;
        while (j < n) {
            if (j - i + 1 > k) i++;
            if (j - i + 1 == k)
                minDiff = min(minDiff, abs(nums[j] - nums[i]));
            j++;
        }
        return minDiff;
    }
};

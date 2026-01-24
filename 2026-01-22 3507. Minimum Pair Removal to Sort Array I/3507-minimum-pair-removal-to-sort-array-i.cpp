using namespace std;

class Solution {
public:
    int minPairIndex(vector<int>& nums) {
        int minSum = INT_MAX;
        int idx = -1;

        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i + 1];
            if (sum < minSum) {
                minSum = sum;
                idx = i;
            }
        }
        return idx;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!is_sorted(nums.begin(), nums.end())) {
            int i = minPairIndex(nums);
            nums[i] += nums[i + 1];
            nums.erase(nums.begin() + i + 1);
            operations++;
        }

        return operations;
    }
};

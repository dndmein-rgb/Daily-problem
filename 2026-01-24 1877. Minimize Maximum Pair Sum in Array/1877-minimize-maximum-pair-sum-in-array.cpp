class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int maxSum = 0;

        while (i < j) {
            maxSum = max(maxSum, nums[i] + nums[j]);
            i++;
            j--;
        }
        return maxSum;
    }
};

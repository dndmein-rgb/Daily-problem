class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int second = INT_MAX, third = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < second) {
                third = second;
                second = nums[i];
            } else if (nums[i] < third) {
                third = nums[i];
            }
        }
        return nums[0] + second + third;
    }
};

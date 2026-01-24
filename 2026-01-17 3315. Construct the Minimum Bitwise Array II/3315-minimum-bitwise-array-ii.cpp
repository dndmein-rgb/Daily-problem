

class Solution {
public:
    vector<long long> minBitwiseArray(vector<int>& nums) {
        vector<long long> ans;

        for (int num : nums) {
            if (num == 2) {
                ans.push_back(-1);
                continue;
            }

            bool found = false;
            long long x = num;

            for (int i = 1; i < 62; i++) {
                if ((x & (1LL << i)) != 0) continue;

                ans.push_back(x ^ (1LL << (i - 1)));
                found = true;
                break;
            }

            if (!found) ans.push_back(-1);
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        int mini = INT_MAX;
        sort(arr.begin(), arr.end());

        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            mini = min(mini, diff);
        }

        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == mini) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};

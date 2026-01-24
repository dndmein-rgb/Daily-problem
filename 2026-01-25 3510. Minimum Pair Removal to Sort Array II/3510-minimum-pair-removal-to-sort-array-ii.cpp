class Solution {
public:
    using ll = long long;

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<ll> a(n);
        for (int i = 0; i < n; i++) a[i] = nums[i];

        vector<int> prev(n), next(n);
        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        multiset<pair<ll,int>> pairs;
        int bad = 0;

        for (int i = 0; i < n - 1; i++) {
            pairs.insert({a[i] + a[i + 1], i});
            if (a[i] > a[i + 1]) bad++;
        }

        int ops = 0;

        while (bad > 0) {
            auto it = pairs.begin();
            int i = it->second;
            int j = next[i];
            pairs.erase(it);

            if (a[i] > a[j]) bad--;

            int L = prev[i];
            int R = next[j];

            if (L >= 0) {
                if (a[L] > a[i] && a[L] <= a[i] + a[j]) bad--;
                if (a[L] <= a[i] && a[L] > a[i] + a[j]) bad++;
                pairs.erase({a[L] + a[i], L});
            }

            if (R < n) {
                if (a[j] > a[R] && a[i] + a[j] <= a[R]) bad++;
                if (a[j] <= a[R] && a[i] + a[j] > a[R]) bad--;
                pairs.erase({a[j] + a[R], j});
            }

            a[i] += a[j];
            next[i] = R;
            if (R < n) prev[R] = i;

            if (L >= 0)
                pairs.insert({a[L] + a[i], L});
            if (R < n)
                pairs.insert({a[i] + a[R], i});

            ops++;
        }

        return ops;
    }
};

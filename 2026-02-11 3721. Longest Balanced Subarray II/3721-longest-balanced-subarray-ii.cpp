#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<int> sum, mn, mx;

    SegmentTree(int n1) {
        n = n1;
        sum.assign(4 * n, 0);
        mn.assign(4 * n, 0);
        mx.assign(4 * n, 0);
    }

    void pull(int node) {
        int l = node * 2;
        int r = node * 2 + 1;

        sum[node] = sum[l] + sum[r];
        mn[node] = min(mn[l], sum[l] + mn[r]);
        mx[node] = max(mx[l], sum[l] + mx[r]);
    }

    void update(int idx, int val) {
        int node = 1, l = 0, r = n - 1;
        vector<int> path;

        while (l != r) {
            path.push_back(node);
            int m = l + (r - l) / 2;

            if (idx <= m) {
                node = node * 2;
                r = m;
            } else {
                node = node * 2 + 1;
                l = m + 1;
            }
        }

        sum[node] = val;
        mn[node] = val;
        mx[node] = val;

        while (!path.empty()) {
            int cur = path.back();
            path.pop_back();
            pull(cur);
        }
    }

    int findRightPre(int target) {
        int node = 1, l = 0, r = n - 1;
        int sumBefore = 0;

        if (!(mn[node] <= target - sumBefore &&
              target - sumBefore <= mx[node]))
            return -1;

        while (l != r) {
            int m = l + (r - l) / 2;
            int lc = node * 2;
            int rc = node * 2 + 1;

            int sumRight = sum[lc] + sumBefore;
            int need = target - sumRight;

            if (mn[rc] <= need && need <= mx[rc]) {
                node = rc;
                l = m + 1;
                sumBefore = sumRight;
            } else {
                node = lc;
                r = m;
            }
        }

        return l;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(n);

        unordered_map<int, int> mpp;
        int ans = 0;

        for (int l = n - 1; l >= 0; --l) {
            int num = nums[l];

            if (mpp.count(num)) {
                seg.update(mpp[num], 0);
            }

            mpp[num] = l;
            seg.update(l, (num % 2 == 0) ? 1 : -1);

            int r = seg.findRightPre(0);

            if (r >= l)
                ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

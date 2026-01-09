class Solution {
public:
    int dfs(TreeNode* root, TreeNode*& ans, int depth, int& maxDepth) {
        if (!root) return depth;

        int left = dfs(root->left, ans, depth + 1, maxDepth);
        int right = dfs(root->right, ans, depth + 1, maxDepth);

        int curr = max(left, right);

        if (left == right && curr >= maxDepth) {
            maxDepth = curr;
            ans = root;
        }

        return curr;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans = nullptr;
        int maxDepth = 0;
        dfs(root, ans, 0, maxDepth);
        return ans;
    }
};

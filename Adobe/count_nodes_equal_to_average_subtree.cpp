/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int averageOfSubtree(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

 private:
  pair<int, int> dfs(TreeNode* root, int& ans) {
    if (root == nullptr)
      return {0, 0};
    const auto [lSum, lCount] = dfs(root->left, ans);
    const auto [rSum, rCount] = dfs(root->right, ans);
    const int sum = root->val + lSum + rSum;
    const int count = 1 + lCount + rCount;
    if (sum / count == root->val)
      ++ans;
    return {sum, count};
  }
};

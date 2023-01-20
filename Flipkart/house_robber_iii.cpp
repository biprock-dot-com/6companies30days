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

const int INF = -1e8;
class Solution {
public:

    pair<int,int>thief(TreeNode* node)
    {
        if(!node) return {INF, 0};

      pair <int,int> lVal = thief(node->left);
      pair <int,int> rVal = thief(node->right);

      lVal.first = max(lVal.first,0);
      lVal.second = max(lVal.second,0);

      rVal.second = max(rVal.second,0);
      rVal.first = max(rVal.first,0);

      int curr_Val = max(node->val,0);

      int cantBeAdded = curr_Val + lVal.second + rVal.second;
      int canBeAdded =max(lVal.first + rVal.first,max({lVal.second,rVal.second,lVal.second + rVal.second,lVal.second+rVal.first,rVal.second+lVal.first }));
      return {cantBeAdded,canBeAdded};
    }
    int rob(TreeNode* root) {
        pair<int,int>r = thief(root);
        return max(r.first, r.second);
    }
};

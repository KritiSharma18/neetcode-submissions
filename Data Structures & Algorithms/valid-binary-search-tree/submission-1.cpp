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
    
    bool isValidBST(TreeNode* root) {
       return check(root, nullptr, nullptr);
    }
private:
    bool check(TreeNode* node, const int* lo, const int* hi) {
        if (!node) return true;
        if (lo && node->val <= *lo) return false;
        if (hi && node->val >= *hi) return false;
        return check(node->left, lo, &node->val) &&
               check(node->right, &node->val, hi);
    }
};

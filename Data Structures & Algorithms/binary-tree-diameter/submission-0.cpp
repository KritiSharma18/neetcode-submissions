class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    // returns height of node (in edges + 1, null = 0), updates diameter along the way
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int l = height(node->left, diameter);
        int r = height(node->right, diameter);
        diameter = max(diameter, l + r);
        return 1 + max(l, r);
    }
};
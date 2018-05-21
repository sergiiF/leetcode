
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        return isNodeValid(root);
    }
    bool isNodeValid(TreeNode* node) {
        bool res = true;
        if (node->left) res &= (node->left->val < node->val)&&isNodeValid(node->left);
        if (node->right) res &= (node->right->val > node->val)&&isNodeValid(node->right);

        return res;
    }

};

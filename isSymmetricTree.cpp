struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return isSymmetricNodes(root->left, root->right);
    }

    bool isSymmetricNodes(TreeNode* l, TreeNode* r) {
        if (!l || !r) return l == r;

        return (l->val == r->val) && isSymmetricNodes(l->left, r->right) && isSymmetricNodes(l->right, r->left);
    }
};Difficulty
DifficultyDifficultyDifficultyDifficultyDifficultyDifficulty

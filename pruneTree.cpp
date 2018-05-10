#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return root;
        root->left = containsOnes(root->left) ? pruneTree(root->left) : 0;
        root->right = containsOnes(root->right) ? pruneTree(root->right) : 0;

        return root;
    }

    bool containsOnes(TreeNode* node) {
        if (!node) return false;

        return node->val || containsOnes(node->left) || containsOnes(node->right);
    }
};

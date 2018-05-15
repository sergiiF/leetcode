#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

// Inorder (Left, Root, Right)
#define RECULSION


#ifdef RECURSION
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        dfs(root, v);

        return v;
    }

    void dfs(TreeNode* node, vector<int>& v) {
        if (!node) return;

        if(node->left) {
            dfs(node->left, v);
        }

        v.push_back(node->val);

        if(node->right) {
            dfs(node->right, v);
        }
    }
};
#endif





#ifdef NORECURSION
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

    }
};
#endif

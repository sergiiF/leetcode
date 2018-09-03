#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
 };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //return dfs(root,val);
        return bfs(root,val);
    }
private:
    TreeNode* bfs(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == val)
                return node;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return nullptr;
    }
    TreeNode* dfs(TreeNode* node, int val) {
        TreeNode* ret;
        if (!node) return node;
        if (node->val == val)
            return node;
        ret = dfs(node->left,val);
        return ret ? ret : dfs(node->right,val);
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};
/*
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
};

*/

#include <queue>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* node1 = q.front(); q.pop();
            TreeNode* node2 = q.front(); q.pop();
            if (!node1 || !node2) {
                if (node1 != node2)
                    return false;
                continue;
            }
            if (node1->val != node2->val)
                return false;

            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);

        }


    }
};

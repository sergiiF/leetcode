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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s || !t) return s == t;

       //find root
       queue<TreeNode*> nodes;
       nodes.push(s);
        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();


            if  (t->val == node->val)
                if (isSameTree(node, t))
                    return true;

            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
        }
        return false;
    }

    bool isSameTree(TreeNode* q, TreeNode* p) {
        if (!p || !q) return p == q;

        return (p->val == q->val) && (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }

};

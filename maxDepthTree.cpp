/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 /*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == 0) return 0;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        return 1 + ((lDepth < rDepth)?rDepth:lDepth);
    }
};
*/

#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
 };
/*
class Solution {
public:
    class stackItem {
    public:
        TreeNode *node;
        int level;

        stackItem(TreeNode* node, int level):node(node), level(level) {}
    };
    int maxDepth(TreeNode* root) {
        if (root == 0) return 0;

        stack<stackItem*> s;
        int res = 0;
        s.push(new stackItem(root,1));
        while(!s.empty()) {
            stackItem* item = s.top();
            res = (res < item->level)?item->level : res;
            s.pop();
            if (item->node->left) s.push(new stackItem(item->node->left, item->level + 1));
            if (item->node->right) s.push(new stackItem(item->node->right, item->level + 1));
            delete item;
        }
        return res;
    }
};
*/

#include <queue>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            ++level;
            int size = q.size();
            while (size--) {
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);

                q.pop();
            }
        }
        return level;
    }
};
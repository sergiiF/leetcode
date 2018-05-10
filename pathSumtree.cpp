#include <queue>
using namespace std;
#define NULL 0
/**
 * Definition for a binary tree node.
 */ struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class Solution {
public:
    class qItem {
    public:
        TreeNode* node;
        int sum;
        qItem(TreeNode* n, int s) : node(n), sum(s) {}
    };
/*
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->val > sum) return false;

        queue<qItem*> q;
        q.push(new qItem(root, root->val));

        while (!q.empty()) {
            qItem* item = q.front();
            q.pop();

            int tmpSum;
            if (item->node->left) {
                tmpSum =  item->sum + item->node->left->val;
                if (tmpSum == sum) {
                    delete item;
                    return true;
                }
                if (tmpSum < sum)
                    q.push(new qItem(item->node->left, tmpSum));
            }
            if (item->node->right) {
                tmpSum = item->sum + item->node->right->val;
                if (tmpSum == sum) {
                    delete item;
                    return true;
                }
                if (tmpSum < sum)
                    q.push(new qItem(item->node->right, tmpSum));
            }
            delete item;
        }
        return false;

    }
    */


    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->val > sum) return false;

        return hps(root,sum,0);


    }

    bool hps(TreeNode* node, int sum, int intermSum) {
        intermSum += node->val;

        if(intermSum > sum) return false;

        if(!node->left && !node->right) { //last element
            if (intermSum == sum) return true;
        }

        if ((node->left && hps(node->left, sum, intermSum)) || (node->right && hps(node->right, sum, intermSum)))
            return true;

        return false;
    }
};

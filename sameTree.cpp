#include <iostream>
#include <vector>

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if ((p == 0) || (q == 0)) {
            return p == q;
        }

       // if (p->val != q->val) return false;
       // if(!isSameTree(p->left, q->left)) return false;
       // if (!isSameTree(p->right, q->right)) return false;

       // return true;

       return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};






int main() {

    Solution s;
}

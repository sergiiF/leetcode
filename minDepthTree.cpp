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
      int minDepth(TreeNode* root) {
        if (!root) return 0;

        int lDepth = minDepth(root->left);
        int rDepth = minDepth(root->right);

        return 1 + ((lDepth < rDepth)?lDepth:rDepth);
      }
  };

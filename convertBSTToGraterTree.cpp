

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};


  class Solution {
  public:
      int sum;

      TreeNode* convertBST(TreeNode* root) {
            sum = 0;

            convert(root);

            return root;
      }

  private:
      TreeNode* convert(TreeNode* root) {
          if (!root) return root;

          if (root->right) convert(root->right);
           root->val = sum = sum + root->val;
          if (root->left) convert(root->left);

          return root;
      }
  };

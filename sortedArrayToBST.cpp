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
     TreeNode* sortedArrayToBST(vector<int>& nums) {
         if (nums.empty()) return 0;

         return dfs(0, nums.size(), nums);
     }

     TreeNode* dfs(int first, int last, vector<int>& nums) {
             int cur = first + (last - first)/2;
             TreeNode* node = new TreeNode(nums[cur]);

             if (first != cur) {
                 node->left = dfs(first, cur, nums);
             }
             if (last != cur+1) {
                 node->right = dfs (cur+1, last, nums);
             }
             return node;
     }
 };

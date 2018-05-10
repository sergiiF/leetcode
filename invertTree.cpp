#include <stack>
#include <algorithm>    // std::reverse
using namespace std;

// #define NULL 0
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
    TreeNode* invertTree(TreeNode* root) {
        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();

            if(tmp) {
                st.push(tmp->left);
                st.push(tmp->right);

                std::swap(tmp->left, tmp->right);
            }

        }
        return root;
    }
};

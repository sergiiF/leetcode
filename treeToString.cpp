#include <string>
#include <sstream>

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
    string tree2str(TreeNode* t) {
        string st;
        if (!t) return st;

        st.append(std::to_string(t->val));

        if (t->left || t->right) {
            st.append("(");
            if (t->left) {
                st.append(tree2str(t->left));
            }
            st.append(")");
            if (t->right) {
                st.append("(");
                st.append(tree2str(t->right));
                st.append(")");
            }
        }
        return st;
    }
};

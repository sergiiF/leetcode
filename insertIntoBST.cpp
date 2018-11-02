#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};



class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return root;
        TreeNode* node = root;
        while (node) {
            if (node->val > val) { //go left
                if (node->left)
                    node = node->left;
                else {
                    node->left = new TreeNode(val);
                    break;
                }
            } else {
                if (node->right)
                    node = node->right;
                else {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};
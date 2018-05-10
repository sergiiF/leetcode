#include <stack>
#include <algorithm>    // std::reverse
using namespace std;

// #define NULL 0
/**
 * Definition for a binary tree node
 */ struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };





class Solution {
public:
    int tilt;

    int findTilt(TreeNode* root) {
        tilt = 0;
        if (!root) return 0;
        treeTilt(root);
        return tilt;
    }


private:
    int treeTilt (TreeNode* node) {
        if (!node) return 0;
        int sumL = treeTilt(node->left);
        int sumR = treeTilt(node->right);
        tilt += abs(sumL-sumR);

        return node->val + sumL + sumR;
    }
};

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
    int kthSmallest(TreeNode* root, int k) {
        //inorder traversal   left-root-right
        int res = 0;
        if (root)
            getKMinDfs(root, k, res);
        return res;
    }
private:
    bool getKMinDfs(TreeNode* node, int& k, int& res) {
        if (k == 0) {
            res = node->val;
            return true;
        }
        if (node->left) 
            if (getKMinDfs (node->left, k, res)) 
                return true;
        --k;
        if (node->right) 
            if (getKMinDfs(node->right, k, res))
                return true;

        return false;
    }

};


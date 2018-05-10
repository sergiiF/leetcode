#define NULL 0
/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return 0;

        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        return root;

    }

/*
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        //find new root
        while (root && (root->val < L)) {
            root=root->right;
        }
        while (root && (root->val > R)) {
            root = root->left;
        }

        TreeNode* curNode = root;
        //check L

        while (true) {
            if (curNode->left && (curNode->left->val >= L)) {
                curNode = curNode->left;
            }
            else if (curNode->right) {
                curNode->left = curNode->right;
                curNode = curNode->left;
            }
            else {
                curNode->left = 0;
                curNode->right = 0;
                break;
            }
        }
        //check R
        while (true) {
            if (curNode->right && (curNode->right->val <= R)) {
                curNode = curNode->right;
            }
            else if (curNode->left) {
                curNode->right = curNode->left;
                curNode = curNode->right;
            }
            else {
                curNode->left = 0;
                curNode->right = 0;
                break;
            }
        }

        return 0;

    }
*/

};

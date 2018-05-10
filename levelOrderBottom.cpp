#include <queue>
#include <vector>
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector <vector<int> > vec;
        if (root == 0) return vec;

        goToBottom(root, vec, 0);
        std::reverse(vec.begin(),vec.end());
        return vec;
    }

    void goToBottom(TreeNode* node, vector<vector<int> > &vec, int level) {
        if (node == 0) return;

        if (vec.size() == level) vec.push_back(vector<int>());
        vec[level].push_back(node->val);

        ++level;
        goToBottom(node->left, vec, level);
        goToBottom(node->right, vec, level);
    }
};

/*
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector <vector<int> > vec;
        if (root = 0) return vec;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            vector<int> children;
            if (node->left) children.push_back(node->left->val);
            if (node->right) children.push_back(node->right->val);

            q.push(node->right);
            q.push(node->left);
        }
        std::reverse(vec.begin(),vec.end());

        return vec;
    }

};
*/

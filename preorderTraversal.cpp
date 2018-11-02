#include <vector>
#include <stack>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        stack<TreeNode*> nodes;
        if (!root) return res;

        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.top(); nodes.pop();

            res.push_back(node->val);
            if (node->right) nodes.push(node->right);
            if(node->left) nodes.push(node->left);
        }
        return res;
    }

};
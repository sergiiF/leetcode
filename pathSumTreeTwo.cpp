#include <vector>
#include <pair>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};



class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> v;
        vector<int> path;
        dfs(root, sum,0, path, v);

        return v;
    }


    void dfs(TreeNode* node, int sum, int tmpSum, vector<int> path, vector<vector<int>>& v) {
        if (!node) return;

        tmpSum+=node->val;

        path.push_back(node->val);

        if ((!node->left && !node->right) && (tmpSum == sum)) {
            v.push_back(path);
            return;
        }

        if(node->left) dfs(node->left, sum, tmpSum, path, v);
        if(node->right) dfs(node->right, sum, tmpSum, path, v);
    }

  };

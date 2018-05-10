#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if (0 == root) return res;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int sum = 0;

            for (int i = 0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(sum/double(size));
        }
        return res;
    }
};

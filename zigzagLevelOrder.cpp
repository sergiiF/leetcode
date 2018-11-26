/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        deque <TreeNode*> dq;
        dq.push_back(root);
        bool zigzag = false;
        while (!dq.empty()) {
            int level_size = dq.size();
            vector<int> level;
            while(level_size-- ) {
                if (zigzag) {
                    TreeNode* node = dq.back(); dq.pop_back();
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                    level.push_back(node->val);
                } else {
                    TreeNode* node = dq.front(); dq.pop_front();
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                    level.push_back(node->val);
                }
                 
            }
            res.push_back(level);
            zigzag = zigzag? false : true;
             
        }
        return res;
    }
};
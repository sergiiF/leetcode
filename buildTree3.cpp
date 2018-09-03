#include <vector>
#include <iostream>

using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
 };


class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.size() != post.size() || pre.empty())
            return nullptr;
        int pr = 0;
        return dfs(pre, post, pr, 0, post.size()-1);
    }

private:
    TreeNode* dfs(vector<int>& pre, vector<int>& post, int& pr, int po_start, int po_end) {
        if (pr >= pre.size() || po_start > po_end) return nullptr;
        TreeNode* root = new TreeNode(pre[pr++]);
        if (po_start == po_end) return root;

        //find idx of next pr in post
        int idx = po_start;
        for (;idx <= po_end; ++idx) {
            if (pre[pr] == post[idx]) break;
        }

        if (idx <= po_end) {
            root->left = dfs (pre, post, pr, po_start, idx-1);
            root->right = dfs(pre, post, pr, idx +1, po_end);
        }
        return root;

    }
};

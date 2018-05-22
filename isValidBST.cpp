#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};


#define NORECURSION

#ifdef RECURSION
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        int prev = 0;
        bool isFirst = true;

        return dfs(root, prev, isFirst);
    }
    bool dfs(TreeNode* node, int& prev ,bool& isFirst) {
        bool res = true;
        if (node->left) {
            res &= dfs(node->left, prev, isFirst);
        }

        if (isFirst) isFirst = false;
        else res &= (prev < node->val);

        prev = node->val;

        if (node->right) {
            res &= dfs(node->right,prev,isFirst);
        }
        return res;
    }

};
#endif

#ifdef NORECURSION
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool first = true;

        stack<TreeNode*> s;
        int prev = root->val;
        TreeNode* current = root;

        while (!s.empty() || current) {
            while (current && current->left) {
                    s.push(current);
                    current = current->left;
            }
            if (!current) {
                current = s.top(); s.pop();
            }
            if (first) first = false;
            else if (current->val <= prev) return false;

            prev = current->val;
            current = current->right;
        }
        return true;
    }

};



#endif

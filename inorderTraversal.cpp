#include <vector>

#include <set>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

// Inorder (Left, Root, Right)
#define SERGEY


#ifdef RECURSION
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        dfs(root, v);

        return v;
    }

    void dfs(TreeNode* node, vector<int>& v) {
        if (!node) return;

        if(node->left) {
            dfs(node->left, v);
        }

        v.push_back(node->val);

        if(node->right) {
            dfs(node->right, v);
        }
    }
};
#endif


#ifdef SERGEY

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;

        if (!root) return v;

        TreeNode* current = root;
        while (!s.empty() || current) {
            if (current) {
                if (current->left) {
                    s.push(current);
                    current = current->left;
                } else {
                    v.push_back(current->val);
                    current = current->right;
                }
            } else {
                // get current from stack, which means left already has been processed
                current = s.top(); s.pop();
                v.push_back(current->val);
                current = current->right;
            }
        }
        return v;

    }
};
#endif


#ifdef NORECURSION

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        set<TreeNode*> marked;
        vector<int> v;

        if (!root) return v;

        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top(); s.pop();

            if ((!node->left && !node->right) || (marked.find(node) != marked.end())) {
                v.push_back(node->val);
                continue;
            }
            if (node->right) {
                s.push(node->right);
            }

            s.push(node);
            marked.insert(node);

            if(node->left) {
                s.push(node->left);
            }

        }
        return v;

    }
};
#endif

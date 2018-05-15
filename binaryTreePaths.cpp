#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};




class Solution {
public:
    inline bool isLeaf(TreeNode* n) {
        return (0 == n->left) && (0 == n->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> v;
        buildPath(root,"", v);

        return v;
    }

    void buildPath(TreeNode* node, string path, vector <string>& v) {
        if (!node) return;

        if(!path.empty())
            path.append("->");

        path.append(to_string(node->val));

        if (isLeaf(node)) {
            v.push_back(path);
            return;
        }

        if(node->left)
            buildPath(node->left, path, v);
        if(node->right)
            buildPath(node->right, path, v);
    }
};

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
class Solution {
public:
struct StackItem {
    StackItem(TreeNode* n) : node(n), visited(false){}
    TreeNode* node;
    bool visited;
};
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack <StackItem> nodes;
        nodes.push({root});

        while (!nodes.empty()) {
            if (nodes.top().visited) {
                res.push_back({nodes.top().node->val});
                nodes.pop();
            } else {
                StackItem &top_item = nodes.top();
                top_item.visited = true;
                if (top_item.node->right){
                    nodes.push({top_item.node->right});
                }
                if (top_item.node->left) {
                    nodes.push({top_item.node->left});
                }
            }
        }
        return res;
    }
};
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (!root) return;

        stack <TreeNode*> s;
        TreeNode* current = root;

        while (!s.empty() || current) {
            if (current) {
                while (current->left) {
                    s.push(current);
                    current = current->left;
                }
            } else {
                current = s.top(); s.pop();
            }
            q.push(current->val);
            current = current->right;
        }

    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();

    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            int next = q.front(); q.pop();
            return next;
        }
    }

private:
    queue<int> q;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

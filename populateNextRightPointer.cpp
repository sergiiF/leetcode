#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeLinkNode* node = q.front(); q.pop();
                if (size) //last element in a row, link is null
                    node->next = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};
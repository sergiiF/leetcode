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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int max = 0;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int levelWidth = 0;
            int nullCount = 0;

            while (size != 0) {
                TreeNode* node = q.front();
                q.pop();
                size--;

                if(node) {
                    if (levelWidth) {
                        levelWidth+=nullCount;
                    }
                    levelWidth++;
                    nullCount = 0;
                    q.push(node->right);
                    q.push(node->left);
                } else {
                    if (levelWidth && size) {
                        nullCount++;

                        q.push(0);
                        q.push(0);
                    }
                }

            }
            if (levelWidth == 0)
                break;
            if (max < levelWidth)
                max = levelWidth;
        }
        return max;
    }


};

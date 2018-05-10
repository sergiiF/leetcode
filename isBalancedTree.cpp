#include <stdlib.h>
#include <cmath>        // std::abs
#include <queue>
#include <iostream>

#define null 0

using namespace std;

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}

      static TreeNode* buildTree(int* arr, int len){
          TreeNode* root = new TreeNode(arr[0]);
          TreeNode* temp;

          queue<TreeNode*> q;
          q.push(root);
          for(int i = 1; i < len; i+=2){
              temp = q.front();
              q.pop();
              int right = i;
              int left = i + 1;
              if (arr[left] != null) {
                  temp->left = new TreeNode(arr[left]);
                  q.push(temp->left);
              }
              if (arr[right] != null) {
                  temp->right = new TreeNode(arr[right]);
                  q.push(temp->right);
              }

          }
          return root;
      }
  };



class Solution {
public:
    bool isBalanced(TreeNode* root) {
        try {
            maxDepth(root);
        } catch (int e) {
            return false;
        } catch (...) {
            throw;
        }

        return true;
    }

    int maxDepth(TreeNode* root) {
        if (root == 0) return 0;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        cout << "Root is: "<<root->val << ", Depths are: "<< lDepth << ", " << rDepth<<endl;
        if ( std::abs(lDepth - rDepth) > 1) throw 47;

        return 1 + ((lDepth < rDepth) ? rDepth:lDepth);
    }
};


int main(){
    int arr[] = {1,2,2,3,3,null,null,4,4};
    TreeNode * root = TreeNode::buildTree(arr, sizeof(arr)/sizeof(int));
    cout << "Result is: "<<Solution().isBalanced(root)<<endl;
}

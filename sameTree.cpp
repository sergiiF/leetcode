#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSameTree1(TreeNode* p, TreeNode* q) {

        if ((p == 0) || (q == 0)) {
            return p == q;
        }

       // if (p->val != q->val) return false;
       // if(!isSameTree(p->left, q->left)) return false;
       // if (!isSameTree(p->right, q->right)) return false;

       // return true;

       return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSameTree2(TreeNode* p, TreeNode* q) {
        if (p && q)
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return (p == q);
    }

    bool isSameTree4(TreeNode* p, TreeNode* q) {
        deque <TreeNode*> stack;

        stack.push_back(p);
        stack.push_back(q);
        while (!stack.empty()) {
            p = stack.back(); stack.pop_back();
            q = stack.back(); stack.pop_back();

            if (p && q) {
                if (p->val != q->val) return false;
                stack.push_back(p->right);
                stack.push_back(q->right);
                stack.push_back(p->left);
                stack.push_back(q->left);
            }
            else {
                if (p == q) continue;
                else return false;
            }
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque <TreeNode*> stack;

        stack.push_back(p);
        stack.push_back(q);
        while (!stack.empty()) {
            p = stack.back(); stack.pop_back();
            q = stack.back(); stack.pop_back();

            if (!p && !q) continue;
            if (!p || !q) return false;

            if (p->val != q->val) return false;

            stack.push_back(p->right);
            stack.push_back(q->right);
            stack.push_back(p->left);
            stack.push_back(q->left);
        }

    }


    bool isSameTree3(TreeNode* p, TreeNode* q) {
        if(!p || !q)
            return p == q;

        deque<TreeNode*> queue;

        queue.push_back(p);
        queue.push_back(q);
        while(!queue.empty()) {
            int size = queue.size();
            if (size%2) return false;
            for (int i=0; i < size; i += 2){
                TreeNode* first = queue.front();
                queue.pop_front();
                TreeNode* second = queue.front();
                queue.pop_front();

                if (!first || !second){
                    if (first != second) {
                        return false;
                    } else {
                        continue;
                    }
                }
                if (first->val != second->val) return false;

                queue.push_back(first->left);
                queue.push_back(second->left);
                queue.push_back(first->right);
                queue.push_back(second->right);
            }
      }
      return true;
    }

};






int main() {

    Solution s;
}

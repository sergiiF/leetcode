#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
         //search node
         //if has no children- delete
         //if has only 1 child - swap with child and delete
         //2 children - swap with next successor - last left in the right one subtree

        if (!root) return root;
        stack <TreeNode*> st;
        TreeNode* current = root;
        TreeNode* parent = nullptr;
       
        while(current) {
            if(current->val == key) break;
            parent = current;
            if(key < current->val) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        if (!current) return root;
        
        //leaf
        if(!current->left && !current->right) {
            if (parent)
                removeNodeWithNoChild(current, parent);
            else {
                delete root;
                root = nullptr;
            }

        }
        //both children
        else if (current->left && current->right) {
            TreeNode* nearest = current->right;
            TreeNode* nearest_parent = current;
            while(nearest->left) {
                nearest_parent = nearest;
                nearest = nearest->left;
            }
            current->val = nearest->val;
            if (nearest->right)
                removeNodeWithOneChild(nearest);
            else
                removeNodeWithNoChild(nearest, nearest_parent);
            
            
        } else { //only one child
            removeNodeWithOneChild(current);
        }

    return root;
    }

    private:
    void removeNodeWithOneChild(TreeNode* node) {
        TreeNode* tmp = node->right; /*if(current->right) */
        if(node->left) {
            tmp = node->left;
        }
        node->val = tmp->val;
        node->left = tmp->left;
        node->right = tmp->right;
        delete tmp;

    }

    void removeNodeWithNoChild(TreeNode* node, TreeNode* parent) {
        if (parent->left == node)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete node;

    }
};


int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    //root->right = new TreeNode(9);
    //root->left->left = new TreeNode(2);
    //root->left->right = new TreeNode(5);
    //root->right->left = new TreeNode(8);
    //root->right->right = new TreeNode(10);
    //root->right->left->left = new TreeNode(3);
    //root->right->left->right = new TreeNode(1);
    
    Solution s; 
    TreeNode* res = s.deleteNode(root,3);
    cout<<res->val<<endl;

}
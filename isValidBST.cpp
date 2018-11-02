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


// #define NORECURSION

#ifdef RECURSION
class Solution {
public:
    bool isValidBST(TreeNode* root) {
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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return dfs(root, INT_MIN, INT_MAX);
    }

    bool dfs(TreeNode* node, int min,int max) {
        if (!node) return true;
        if (min > max || node->val <= min || node->val > max) {
            return false;
        }
        return dfs(node->left, min, node->val) && dfs(node->right, node->val, max);
    }
    struct StackItem{
        TreeNode* node;
        bool left_processed;
        StackItem(TreeNode* n, bool flag = false):node(n), left_processed(flag){}
    };

    bool isValidBST1(TreeNode* root) {
        if(!root) return true;
        stack<StackItem> st;
        st.push({root});
        int prev = INT_MIN;
        while(!st.empty()) {
            StackItem& item = st.top(); //st.pop();
            if (item.node->left && !item.left_processed) {
                item.left_processed = true;
                st.push({item.node->left});
            } else {
                if (prev > item.node->val)
                    return false;
                prev = item.node->val;
                st.pop();
                if (item.node->right) 
                    st.push({item.node->right});
            }
        }
        return true;
    }


};


int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    //root->right->left = new TreeNode(2);
    //root->right->right = new TreeNode(4);
    //root->right->left->left = new TreeNode(3);
    //root->right->left->right = new TreeNode(1);
    
    Solution s; 
    cout<<s.isValidBST1(root)<<endl;
    //cout<<newTree->val<<' '<<newTree->left->val<<' '<<newTree->left->left->val<<newTree->left->right->val<<endl;

}
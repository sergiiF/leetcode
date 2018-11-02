#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(0), right(0) {}
 };

/*Build tree from preorder and inorder vectors*/

class Solution {
public:
    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
            return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* dfs(vector<int>& pre, vector<int>& in, int pre_start, int pre_end, int in_start, int in_end) { //here vector[start, end]
        if (pre.size()!= in.size() || pre.size() == 0)
            return nullptr;
        cout<< pre_start<<":"<<pre_end<<"--"<<in_start<<":"<<in_end<<endl;
        TreeNode* root = new TreeNode(pre[pre_start]);
        cout << "Adding "<<root->val<<endl;
        if (pre_start >= pre_end) return root;

        int idx = findIdx(in, in_start, in_end, root->val);

        if (idx == -1) {
            cout<<"Value "<<root->val<<" not found"<<endl;
            return nullptr;
        }
        int offs = idx - in_start;
        if (idx > in_start) root->left = dfs(pre, in, pre_start + 1, pre_start + offs, in_start, idx - 1);
        if (idx < in_end) root->right = dfs(pre, in, pre_start + offs + 1, pre_end, idx + 1, in_end);

        return root;
    }

    int findIdx(vector<int>& v, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (v[i] == val) return i;
        }
        return -1;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty() || inorder.size() != preorder.size())
            return nullptr;
        auto root_it = preorder.begin();
        return buildTreeDfs(preorder, inorder, inorder.begin(), inorder.end() - 1, root_it);
    }

    TreeNode* buildTreeDfs(vector<int>& preorder, vector<int>& inorder, vector<int>::iterator in_start, vector<int>::iterator in_end, vector<int>::iterator& pre_idx){
        if (in_start < inorder.begin() || in_end >= inorder.end() || in_start > in_end) 
            return nullptr;
        auto it = find(in_start, in_end, *pre_idx);
        if(it == preorder.end())
            return nullptr;
        TreeNode* node = new TreeNode(*pre_idx++);
        node->left = buildTreeDfs(preorder, inorder, in_start, it - 1, pre_idx);
        node->right = buildTreeDfs(preorder, inorder, it + 1, in_end, pre_idx);

        return node;
    }
};



int main (){
    vector <int> pre{1,2,3};
    vector <int> in{3,2,1};

    Solution s;
    TreeNode* node = s.buildTree(pre, in);
    if (node) cout <<"RESULT: "<< node->val<<endl;
    else cout << "Something went wrong"<<endl;

}



/*
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if (preorder.empty()) return NULL;

      int c_pre = 0, c_in = 0;
      TreeNode *root = new TreeNode(preorder[c_pre++]), *ptr = NULL, *pre = NULL;
      ptr = root;

      stack<TreeNode*> st;
      st.push(root);

      while (c_in < inorder.size()) {
          if (!st.empty() && st.top()->val == inorder[c_in]) {
              pre = st.top();
              st.pop();
              c_in++;
          } else {
              ptr = new TreeNode(preorder[c_pre++]);
              if (pre != NULL) {
                  pre->right = ptr;
                  pre = NULL;
              } else {
                  st.top()->left = ptr;
              }
              st.push(ptr);
          }
      }
      return root;
  }
*/

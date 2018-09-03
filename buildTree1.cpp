#include <vector>
#include <iostream>

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

/*Build tree from inorder and postorder vectors*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()!= postorder.size() || inorder.size() == 0)
            return nullptr;
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
    TreeNode* dfs (vector<int>& in, vector<int>& post, int in_start, int in_end, int po_start, int po_end) {
        cout << in_start<< ":"<<in_end<<"  :  "<<po_start<<":"<<po_end<<endl;
        TreeNode* root = new TreeNode(post[po_end]);
        cout<<"adding node "<<root->val<<endl;

        if (po_start == po_end) return root;

        int in_root_index = findIdx(in, post[po_end],in_start, in_end);
        cout <<"..."<<root->val << " index is "<<in_root_index<<endl;

        if (in_root_index == -1) {
            cout <<"value "<<post[po_end]<<" not found"<<endl;
            return nullptr;
        }
        int subtree_size = in_root_index - in_start;
        if (in_root_index > in_start) {
            root->left = dfs(in, post, in_start, in_root_index-1, po_start, po_start + subtree_size - 1);
        }
        if (in_root_index < in_end ) {
            root->right = dfs(in, post, in_root_index + 1, in_end,  po_start + subtree_size, po_end-1);
        }
        return root;
    }

    int findIdx(const vector<int>&in, int val, int in_start, int in_end) {
        for (int i = in_start; i <= in_end; i++) {
            if (in[i] == val) return i;
        }
        return -1;
    }
};

int main (){
    vector <int> in{1,9,10,3,15,20,27};
    vector <int> post{1,10,9,15,27,20,3};

    Solution s;
    TreeNode* node = s.buildTree(in,post);
    if (node) cout <<"RESULT: "<< node->val<<endl;
    else cout << "Something went wrong"<<endl;

}

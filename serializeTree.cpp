
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        if(!root) return str;

        queue<TreeNode*> q;
        q.push(root);
        int null_count= 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front(); q.pop();
                if (!node) {
                    ++ null_count;
                    continue;
                }
                if(null_count) {
                    while(null_count) {
                        --null_count;
                        str.append("x ");
                    }
                }

                str.append(to_string(node->val)+' ');
   

                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        queue<TreeNode*> q;
        int idx = 0;

        TreeNode* root = newNode(data, &idx);
        if (!root) return root;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* node = q.front(); q.pop();
                node->left = newNode(data, &idx);
                node->right = newNode(data, &idx);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }

    TreeNode* newNode(const string& data, int* idx) {
        if (*idx>=data.length()) return nullptr;
        int mul = 1;

        int val = 0;
        while (*idx < data.length() && !isspace(data[*idx])) {
            if (data[*idx] == 'x') {
                *idx+=2;
                return nullptr;
            }
            if (data[*idx] == '-')
                mul = -1;
            else
                val = mul * (val*10 + data[*idx] - '0');
            ++(*idx);
        }
        ++(*idx);
        return new TreeNode(val);
    }
};


int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(3);
    root->right->left->right = new TreeNode(1);
    
    Codec codec; 
    string res =  codec.serialize(root);
    cout<< res<<endl;
    TreeNode* newTree = codec.deserialize(res);
    cout<<newTree->val<<' '<<newTree->left->val<<' '<<newTree->right->val<<endl;
    //cout<<newTree->val<<' '<<newTree->left->val<<' '<<newTree->left->left->val<<newTree->left->right->val<<endl;

}
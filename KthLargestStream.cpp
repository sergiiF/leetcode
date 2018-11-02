#include <vector>
#include <iostream>
using namespace std;


class KthLargest {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        int count;
        TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr, int c = 1): val(v), left(l),right(r), count(c) {}
    };
public:
    KthLargest(int k, vector<int> nums): rank(k) {
       //make tree
       while(!nums.empty()) {
            addNode(nums.back());
            nums.pop_back();
        }
    }
    
    int add(int val) {
        //insert into tree and return kth largest
        addNode(val);

        //find kth largest;
        return findKthNode(root, 0);
    }
    private:
    int findKthNode(TreeNode* node, int count) {
        if (!node->right && count + 1 == rank)
            return node->val;
        int right_rank = (node->right==nullptr ? 1+ count : node->right->count + 1 + count);
        if (node->right && right_rank == rank)
            return node->val;
        if (node->right && right_rank > rank)
            return findKthNode(node->right, count);
        if (node->left)
            return findKthNode(node->left,right_rank);
        return -1;
    }

    void addNode(int val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }

        TreeNode* node = root;
        while(node) {
            ++node->count;
            if(val < node->val) {
                if (node->left)
                    node = node->left;
                else {
                    node->left = new TreeNode(val);
                    break;
                }
            } else {
                if (node->right)
                    node = node->right;
                else {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        }
    }
    TreeNode* root = nullptr;
    int rank = 0;
};


int main() {
    vector<int> v{4,5,8,2};
    KthLargest ThirdLargest(3,v);
 
 /*
 ["KthLargest","add","add","add","add","add"]
[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]
 */
    cout<<ThirdLargest.add(3)<<endl;
    cout<<ThirdLargest.add(5)<<endl;
    cout<<ThirdLargest.add(10)<<endl;
    cout<<ThirdLargest.add(9)<<endl;
    cout<<ThirdLargest.add(4)<<endl;
}
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
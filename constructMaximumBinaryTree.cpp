#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};


/*
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = 0;

        int index = findMax(nums);
        if (index != -1) {
            root = new TreeNode(nums[index]);

            vector<int> lv(nums.begin(), nums.begin() + index);
            if (lv.size()) root->left = constructMaximumBinaryTree(lv);

            vector<int> rv(nums.begin() + index + 1, nums.end());
            if (rv.size()) root->right = constructMaximumBinaryTree(rv);
        }
        return root;

    }

private:
    int findMax(vector<int>& nums) {
        int max = 0;
        int index = -1;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (max <= nums[i])
            {
                max = nums[i];
                index = i;
            }
        }
        return index;
    }
};
*/

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = 0;

        return construct(nums, 0, nums.size());

    }

private:

    TreeNode* construct(vector<int>& nums, int begin, int end) {
        TreeNode* root = 0;
        if (begin >= end) return root;

        int index = findMax(nums, begin, end);
        if (index != -1) {
            root = new TreeNode(nums[index]);

            root->left = construct(nums, begin, index);
            root->right = construct(nums, index + 1, end);
        }
        return root;

    }



    int findMax(vector<int>& nums, int begin, int end) {
        int max = 0;
        int index = -1;
        for (int i = begin; i < end; i++) {
            if (max <= nums[i])
            {
                max = nums[i];
                index = i;
            }
        }
        return index;
    }
};

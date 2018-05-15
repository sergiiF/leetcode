#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(0) {}
 };

/**
 * Definition for a binary tree node.
 */
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(0), right(0) {}
 };


 class Solution {
 public:
     TreeNode* sortedListToBST(ListNode* head) {
         if (!head) return 0;
         //put list to vector
         vector <int> v;
         while (head) {
             v.push_back(head->val);
             head = head->next;
         }

         return nextNode(0, v.size(), v);

     }

     TreeNode* nextNode(int l, int r, vector<int>& v) {
         int cur = l + (r-l)/2;
         TreeNode* node = new TreeNode(v[cur]);
         if (l!=cur) {
             node->left = nextNode(l, cur, v);
         }
         if ((1+cur)!=r) {
             node->right = nextNode(cur +1, r, v);
         }
         return node;
     }
 };

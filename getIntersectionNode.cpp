/**
 * Definition for singly-linked list.
 */ 
#include <stack>
using namespace std;
struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(0) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || ! headB) return nullptr;
        stack<ListNode*> sA;
        stack<ListNode*> sB;
        ListNode* node = headA;
        while(node) {
            sA.push(node);
            node = node->next;
        }
        node = headB;
        while(node) {
            sB.push(node);
            node = node->next;
        }
        node = nullptr;
        while(!sA.empty() && !sB.empty()) {
            ListNode* nodeA = sA.top();
            ListNode* nodeB = sB.top();
                if (nodeA->val != nodeB->val)
                    break;
                node = sA.top();
                sA.pop(); sB.pop();
        }
        return node;
        
    }
};

int main() {
    ListNode* headA = new ListNode(1);
    ListNode* headB = new ListNode(2);
    headB->next = new ListNode(1);
    Solution s;
    s.getIntersectionNode(headA, headB);
}
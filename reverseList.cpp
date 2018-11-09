#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 */ struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head->next;
        ListNode* prev = nullptr;
        while (cur) {
            head->next = prev;
            prev = head;
            head = cur;
            cur = cur->next;
        }
        head->next = prev;
        return head;
    }
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);


    Solution s;

    ListNode* res = s.reverseList(head);

    while(res) {
        cout<<res->val<<" ";
        res= res->next;

    }
    cout<<endl;
}
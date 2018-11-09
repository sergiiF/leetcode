
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(0) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* nextNode = chooseNextNode(l1,l2);
        ListNode* newList = nextNode;
        while (nextNode) {
            nextNode->next = chooseNextNode(l1,l2);
            nextNode = nextNode->next;
        }
        return newList;
    }
private:
    ListNode* chooseNextNode(ListNode* &l1, ListNode* &l2){
        ListNode* nextNode;
        if (!l1 && !l2) {
            return nullptr;
        }
        if (!l1) {
            nextNode = new ListNode(l2->val);
            l2 = l2->next;
        } else if (!l2) {
            nextNode = new ListNode(l1->val);
            l1= l1->next;
        } else {
            if (l1->val < l2->val) {
                nextNode = new ListNode(l1->val);
                l1= l1->next;
            } else {
                nextNode = new ListNode(l2->val);
                l2 = l2->next;
            }
        }        
        return nextNode;
    }

};
#include <iostream>
int main() {
    std::cout<<2/10<<std::endl;
    ListNode* l1;
    ListNode* l2;

    l1 = new ListNode(1);
    l1->next = new ListNode(3);
    //l1->next->next = new ListNode(5);

    l2 = new ListNode(2);
    l2->next = new ListNode(4);
    //l2->next->next = new ListNode(6);

    Solution s;
    s.mergeTwoLists(l1,l2);

}
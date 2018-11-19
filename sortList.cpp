#include <iostream>
using namespace std;



 /* Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //while size af chank > 2 recursievly sort
        if(!head || !head->next) return head;
        return mergeSort(head);
        //return head;
    }
    private:
    ListNode* mergeSort(ListNode* head) {
        ListNode* newHead = nullptr;

        ListNode* first = head;
        ListNode* second = nullptr;
        while (first) {
            ListNode* firstChank = first;
            ListNode* secondChank = first->next ? first->next->next : nullptr;
            first = secondChank && secondChank->next ? secondChank->next->next : nullptr;
            
            firstChank = sortChank(firstChank);
            secondChank = sortChank(secondChank);

            firstChank = mergeChanks(firstChank, secondChank);
            newHead = mergeChanks(newHead, firstChank);
        }
        return newHead;
    }

    ListNode* sortChank (ListNode* chHead){
        if (!chHead || !chHead->next) return chHead;
        if (chHead->val > chHead->next->val) {
            swap(chHead->val, chHead->next->val);
        }
        chHead->next->next = nullptr;
        return chHead;
    }

    ListNode* mergeChanks(ListNode* first, ListNode* second) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        if (!first) return second;
        if (!second) return first;

        if (first->val < second->val) {
            head = cur = first;
            first = first->next;
        } else{
            head = cur = second;
            second = second->next;
        }

        while (first && second) {
            if (first->val < second->val) {
                cur->next = first;
                first = first->next;
            } else {
                cur->next = second;
                second = second->next;
            }
            cur = cur->next;
        }
        if (first) {
            cur->next = first;
        } else if (second) {
            cur->next = second;
        }
        return head;
    }
};



int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(10);
    head->next->next->next->next = new ListNode(1);


    Solution s;
    head = s.sortList(head);
    while(head) {
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}
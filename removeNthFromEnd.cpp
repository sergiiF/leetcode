#include <string> 
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <functional>     // std::greater, less
#include <iostream>
#include <algorithm>
// #include <list>
using namespace std;



// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
//        if (n == 1 && !head->next) {
//            delete head;
//            return nullptr;
//       }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && n--){
            fast = fast->next;
        }
        if (n > 0) return head;
        if (!fast) {
            ListNode* tmp = head->next;
            delete head;
            head= tmp;
            return head;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        //remove element after slow
        ListNode* tmp = slow->next;                                                 //1 2 3 4 5
        slow->next = slow->next->next;
        delete tmp;

        return head;
    }
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);


    Solution s;

    ListNode* res = s.removeNthFromEnd(head, 2);

    while(res) {
        cout<<res->val<<" ";
        res= res->next;

    }
    cout<<endl;
}
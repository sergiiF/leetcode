#include <vector>
#include <iostream>
#include <iterator>

using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* middle = head;
        int size = 1;
        int mid_pos = 1;

        while (head!= nullptr) {
            int new_mid_pos = (size+1)%2 ? (size+1)/2 +1 : (size+1)/2;
            if (new_mid_pos > mid_pos) {
                ++mid_pos;
                middle =middle->next;
            }
            head = head->next;
            ++size;
        }
        return middle;
    }
    //from leetcode:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* middle = head;

        while (head && head->next) {
            middle = middle->next;
            head = head->next->next;
        }
        return middle;
    }
};


int main () {
    Solution s;
    ListNode* list = new ListNode(0);
    for (int i = 1; i <6; ++i) {
        list->next = new ListNode(i);
        list = list->next;
    }
    cout<<s.middleNode(list)->val<<endl;


}

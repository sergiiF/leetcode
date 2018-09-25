/*
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields,
it holds a field named both, which is an XOR of the next node and the previous node.
 Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
*/
#include <iostream>
#include <exception>
#include <memory>

using namespace std;

struct listNode {
    listNode(int e = 0):val{e}, both{} { }
    int val;
    long both;

};

class xorList {
public:
    xorList():head(nullptr), last(nullptr), size{} {};
    ~xorList();

    void add(int element);
    listNode* get (int index);
private:
    listNode* head;
    listNode* last;

    int size;

};

void xorList::add(int elem) {
    listNode* node = new listNode(elem);
    cout<<"before add"<<endl;
    ++size;
    if (!last) {
        head = last = node;
    } else {
        node->both = (long)last;
        last->both = last->both ^ (long)node;
        last = node;
    }
    cout<<hex<<"after add: "<<node<<endl;
}

xorList::~xorList() {

    while (last != head) {
        cout<<"deleting "<<last->val<<endl;
        listNode* cur = (listNode*)last->both;
        cur->both ^= (long)last;
        delete last;
        last = cur;
    }
    if (head) cout<<"deleting head "<<head->val<<endl;
    delete head;
}

listNode* xorList::get(int index) {
    if (size < index)
        throw out_of_range("");

    listNode* cur = head;
    listNode* next = nullptr;
    listNode* prev = nullptr;
    for (int i = 0; i<index; i++) {
        next = (listNode*)(cur->both^(long)prev);
        prev = cur;
        cur = next;
    }
    cout<<hex<<"Get return: "<<cur<<endl;
    return cur;
}



int main() {
    xorList list;
    list.add(1);
    list.add(2);
    list.add(3);

    listNode* node = list.get(0);
    cout<<"Get first: "<<node->val<<endl;
    node = list.get(2);
    cout<<"Get last: "<<node->val<<endl;
}

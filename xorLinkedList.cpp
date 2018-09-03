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
    listNode(int e = 0):val{e},both{} {}
    int val;
    int both;

};

class xorList {
public:
    xorList():head(nullptr), last(nullptr), size{} {};
    ~xorList(){};

    void add(int element);
    listNode get (int index);
private:
    shared_ptr<listNode> head;
    shared_ptr<listNode> last;
    int size;

};

void xorList::add(int elem) {
    shared_ptr<listNode> node(new listNode(elem));
    //node->val = elem;
    ++size;
    if (!last) {
        head = last = node;
    } else {
        last->both^=node;
        last = node;
    }
}

listNode* xorList::get(int index) {
    if (size < index)
        throw out_of_range;

    shared_ptr<listNode> next = head;
    shared_ptr<listNode> prev = nullptr;
    for (int i = 0; i<index; i++) {
        if (prev) {
            prev = next;
            next = next->both^prev;
        }
    }
    return next;
}



int main() {
    xorList list;
    list.add(1);
    list.add(2);
    list.add(3);

    shared_ptr<listNode> node = list.get(0);
    cout<<"Get first: "<<node->val<<endl;
    node = list.get(2);
    cout<<"Get last: "<<node->val<<endl;
}

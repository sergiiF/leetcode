#include <vector>
#include <queue>
#include <assert.h>
#include <list>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
public:
  //   initialize your data structure here.
    MinStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
 
        auto it = lower_bound(minQueue.begin(), minQueue.end(), x);
        minQueue.emplace(it,x);
    }
    
    void pop() {
        int tmp = st.back();

        minQueue.erase(find(minQueue.begin(), minQueue.end(), tmp));
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minQueue.front();        
    }
private:
    vector<int> st {};
    list<int> minQueue{};
    
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


int main() {
     MinStack obj = MinStack();
    obj.push(5);
    obj.push(3);
    obj.push(2);
    obj.push(1);
    obj.push(4);
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();

    assert(obj.getMin() == 5);
    obj.pop();
    //assert(obj.getMin() == 0);
}
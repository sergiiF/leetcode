#include <string>
#include <cassert>
#include <unordered_map>
#include <stack>
#include <iostream>
using namespace std;

const char end_of_word = '#';


class Trie;


struct TrieNode {
    TrieNode(int v = 0): val(v) {}
    int val;
    unordered_map<char, TrieNode*> children;
};


class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        if (key.empty()) return;
        TrieNode* node = root;
        for (char letter : key) {
            if (!(node->children)[letter]) {
                (node->children)[letter] = new TrieNode();
            }
            node = (node->children)[letter];
        }
        node->val = val;
    }
    
    int sum(string prefix) {
        if (prefix.empty()) return 0;
        TrieNode* node = root;
        for (char letter : prefix) {
            if (node->children.find(letter) == node->children.end()) {
                return 0;
            }
            node = (node->children)[letter];
        }
        //return recursion(node);
        stack<TrieNode*> st;
        st.push(node);
        int result = 0;
        while(!st.empty()) {
            TrieNode* node = st.top();
            st.pop();
            result += node->val;
            for (auto child : node->children) {
                st.push(child.second);
            }
        }
        return result;
    }
private:
    TrieNode* root;
    int recursion (TrieNode* node) {
        int res = node->val;
        for (auto child : node->children) {
            res += recursion(child.second);
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main() {
    MapSum obj = MapSum();
    /*
    obj.insert("apple", 3);
    assert(obj.sum("ap") == 3);
    obj.insert("app", 2);
    assert(obj.sum("ap") == 5);
    */
    obj.insert("a", 3);
    //assert(obj.sum("ap") == 3);
    cout<<obj.sum("ap")<<endl;
    obj.insert("b", 2);
    //assert(obj.sum("a") == 5);
    cout<<"Find a: "<<endl;
    cout<<obj.sum("a")<<endl;
}
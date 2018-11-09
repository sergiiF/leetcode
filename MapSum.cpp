#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

const char end_of_word = '#';


class Trie;


struct TrieNode {
    TrieNode(int v = 0, bool flag = false): val(v), isWord(flag) {}
    int val;
    bool isWord;
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
        node->isWord = true;
        node->val = val;
    }
    
    int sum(string prefix) {
        if (prefix.empty()) return 0;
    }
private:
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
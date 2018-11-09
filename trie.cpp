#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

const char end_of_word = '#';


class Trie;


struct TrieNode {
    //TrieNode(char c = ''): val(c) {}
    //char val;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (root == nullptr) {
            root = new TrieNode();
        }
        TrieNode* node = root;
        for (char letter: word) {
            if (!(node->children)[letter]) {
                //(node->children)[letter] = new TrieNode(letter);
                (node->children)[letter] = new TrieNode();
            }
            node = (node->children)[letter];
        }
        //(node->children)[end_of_word] = new TrieNode(end_of_word);
        (node->children)[end_of_word] = new TrieNode();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        word.push_back(end_of_word);
        return startsWith(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            node = (node->children)[c];
            if (!node)
                return false;
        }
        return true;
    }
private:

    TrieNode* root = nullptr;

};

int main() {
    Trie trie = Trie();

    trie.insert("apple");
    assert(trie.search("apple") == true);   // returns true
    assert(trie.search("app") ==  false);     // returns false
    assert(trie.startsWith("app") == true); // returns true
    trie.insert("app");   
    assert(trie.search("app") == true);     // returns true

}
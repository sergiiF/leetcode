#include <string>
#include <cassert>
#include <unordered_map>
#include <stack>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TrieNode {
    TrieNode(bool flag = false): isWord(flag) {}
    bool isWord;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char letter: word) {
            if (node->children.find(letter) == node->children.end()) {
                (node->children)[letter] = new TrieNode();
            }
            node = (node->children)[letter];
        }
        node->isWord = true;
    }

    string getRoot(const string& word) {
        string result = "";
        TrieNode* node = root;
        for (char c: word) {
            if (node->children.find(c) == node->children.end()) {
                break;
            }
            result +=c;
            node = (node->children)[c];
            if (node->isWord) return result;
        }
        return node->isWord? result : "";
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            node = (node->children)[c];
            if (!node)
                return false;
        }
        return node->isWord;
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

    TrieNode* root;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if (dict.empty()) return sentence;
        if (sentence.empty()) return sentence;

        Trie trie;
        for(auto word: dict) {
            trie.insert(word);
        }
        string result;
        istringstream iss(sentence);
        string word;
        while (iss>>word) {
            string root = trie.getRoot(word);
            result += root.empty()? word : root;
            result +=' ';
        }
        result.pop_back(); //remove last space
        return result;
    }
};


int main() {
    vector <string> dict = {"a", "aa", "aaa", "aaaa"};
    string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    //vector<string> dict = {"cat", "bat", "rat"};
    //string sentence = "the cattle was rattled by the battery";
    //string sentence = "the ca was rattled by the ba tery";
    Solution s;
    cout<< s.replaceWords(dict, sentence)<<"!"<<endl;
}
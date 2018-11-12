#include <vector>
#include <string>
#include <climits>
#include <map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;


struct TrieNode {
    vector<TrieNode*> children;
    bool isWord;
    TrieNode(bool flag = false):isWord(flag), children(26){}
};
class Trie {
public:
    Trie(const vector<string>& words) {
        root = new TrieNode;
        for(string word: words) {
            insert(word);
        }
    }
    pair<bool, bool> contains(const string& prefix) const {
        TrieNode* node = root;
        for( char c : prefix) {
            if (node->children[c -'a'] == nullptr) {
                return make_pair(false, false);
            }
            node = node->children[c -'a'];
        }
        if (node->isWord) return make_pair(true,true);
        return make_pair(true, false);
    }

private:
    TrieNode* root;

    void insert( string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

};


struct Point{
    int row;
    int column;
    Point(int r = 0, int c = 0): row(r), column(c){}
    Point(const Point& p) {
        row = p.row;
        column = p.column;
    }
    Point(const Point&& p) {
        row = p.row;
        column = p.column;
    }
};
    Point operator+(const Point& p1,const Point& p2) {
        Point p3;
        p3.row = p1.row + p2.row;
        p3.column = p1.column + p2.column;
        return p3;
        //return (p1.row + p2.row, p1.column + p2.column);
    }
    bool operator==(const Point& p1,const Point& p2) {
        return p1.row == p2.row && p1.column == p2.column;
    }

    bool inBorders(Point point, int maxRow, int maxColumn) {
        return (point.row >= 0 && point.row < maxRow && point.column >=0 && point.column < maxColumn);
    }
    

struct StackNode {
    Point point;
    string str;
    vector<Point> visited;
    
    StackNode(Point p = {}, string s = {}, vector<Point> v = {}): point(p), str(s), visited(v){}
};



class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        //create trie from words
        //for each letter on board find words in the trie
        //return list of found words
        Trie trie(words);

        const int rows = board.size();
        const int columns = board.front().size();

        vector<string> result;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                string letter(1, board[row][column]);
                auto foundInTrie = trie.contains(letter);
                if (foundInTrie.first) {
                    if (foundInTrie.second) {
                        result.push_back(letter);
                    }
                    crossWords(row, column, board, trie, result);
                }
            }
        }
        return result;
    }


    void crossWords(int row, int column, const vector<vector<char>>& board,const Trie& trie, vector<string>& result) {
        Point adjasent[] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
        stack<StackNode> st;
        st.push(StackNode(Point(row, column), string(1, board[row][column])));
        while (!st.empty()) {
            StackNode node = st.top(); st.pop();
            for (auto p : adjasent) {
                Point newPoint(node.point + p);
                if (inBorders(newPoint, board.size(), board.front().size()) && find(node.visited.begin(), node.visited.end(), newPoint) == node.visited.end()) {
                    string newStr = node.str + board[newPoint.row][newPoint.column];
                    auto foundInTrie = trie.contains(newStr);
                    if (foundInTrie.second) {
                        result.push_back(newStr);
                    }
                    if (foundInTrie.first) {
                        StackNode newNode(newPoint, newStr, node.visited);
                        newNode.visited.push_back(node.point);
                        st.push(newNode);
                    }
                }
            }
        }
    }
};


int main() {
    vector<string> words = {"oath","pea","eat","rain"};
    vector<vector<char>> board = { {'o','a','a','n'},  {'e','t','a','e'},  {'i','h','k','r'}, {'i','f','l','v'}};

    Solution s;
    vector <string> res = s.findWords(board, words);

    for (auto s: res) {
        cout<<s<<" ";
    }
    cout<<endl;
    //Output: ["eat","oath"]
}
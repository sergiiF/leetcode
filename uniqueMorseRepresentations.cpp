#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string alphabet[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."};

        set<string> tr;

        for (int i = 0; i < words.size(); i++) {
            string conc = "";
            for (int j = 0; j < words[i].length(); j++) {
                conc += alphabet[(int)words[i][j] - 97];
            }
            tr.insert(conc);
        }
        return tr.size();
    }
};

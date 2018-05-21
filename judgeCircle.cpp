#include<string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int R = 0;
        int L = 0;
        int U = 0;
        int D = 0;

        for (int i = 0; i < moves.size();i++) {
            switch (moves[i]) {
                case 'R': R++; break;
                case 'L': L++; break;
                case 'U': U++; break;
                case 'D': D++; break;
            }
        }
        return !(R-L+U-D);
    }
};

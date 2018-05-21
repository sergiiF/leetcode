#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> v;
        while (left<=right) {
            int i = left;
            while (i) {
                if (!i||!(i%10)||(left%(i%10))) {
                    break;
                }
                i /= 10;
            }
            if (!i)
                v.push_back(left);
            left++;
        }
        return v;
    }

};


int main () {
    cout << 128%10<<endl;
    return 0;
}

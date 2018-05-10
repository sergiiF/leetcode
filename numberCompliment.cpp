#include <iostream>
#include <unistd.h>

using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int mask = 0x80000000;
        while ((mask & num) == 0){
            mask >>= 1;
        }
        mask ^= -1;
        return (num & mask) ^ mask;
    }
};

int main() {

    Solution s;
    std::cout<<s.findComplement(20)<<std::endl;
    return 0;
}

#include <iostream>
using namespace std;


class Solution {
public:
    bool hasAlternatingBits(int n) {
        n ^= n & 1 ? n << 1 : n >> 1; // The result should be all 1
        return bool(!((n + 1) & n));
    }
};

int main()
{
    Solution s;
    cout<<s.hasAlternatingBits(5)<<endl;
    cout<<s.hasAlternatingBits(6)<<endl;
    cout<<s.hasAlternatingBits(10)<<endl;
    cout<<s.hasAlternatingBits(11)<<endl;
    return 0;
}

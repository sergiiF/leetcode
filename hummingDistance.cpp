#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y);
};

int Solution::hammingDistance(int x, int y)
{
    int a = x^y;
    int count = 0;
    for (int i=0; i <= 31; i++){
        if ((1<<i) & a){
            count++;
        }
    }
    return count;
}



int main()
{
    Solution s;
    cout << s.hammingDistance(2, 7)<<endl;
    return 0;
}

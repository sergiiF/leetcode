#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //if (A[i] & 1) -->even
        if (A.empty()) return A;
        int even = 0, odd = A.size() - 1;
        while ( even != odd) {
            if (A[even] & 1) { //odd -->swap
                cout<<A[even]<<" is even. Swap with "<<A[odd]<<endl;
                swap(A[even], A[odd--]);
            } else {
                ++even;
            }
        }
        return A;
    }
};


int main () {
    vector <int> vec;
    for (int x : vec) {
        cout<<x<<" ";
    }
    cout <<endl;

    Solution s;

    s.sortArrayByParity(vec);

    for (int x : vec) {
        cout<<x<<" ";
    }
    cout <<endl;
}

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sizeA = A.size();
        int sizeB = B.size();
        int res = 0;

        if (!sizeA || !sizeB) return res;

        for (int la = 0; (la < sizeA) && (res < (sizeA - la)); la++) {
            for (int lb = 0; (lb < sizeB) && (res < (sizeB - lb)); lb++) {
                int count = 0;
                while ((la + count < sizeA)&& (lb + count < sizeB) && (A[la+count] == B[lb+count])) {
                    count++;
                }
                if (res < count) res = count;
            }
        }

        cout<<"Res = "<<res<<endl;
        return res;
    }
};


int main () {
    vector<int> a{0,0,0,0,0,0,1,0,0,0};
    vector<int> b{0,0,0,0,0,0,0,1,0,0};
    Solution s;
    int res = s.findLength(a,b);
    cout << res<<endl;
    return 0;

}

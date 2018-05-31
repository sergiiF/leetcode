#include <vector>
#include <iostream>
using namespace std;

#ifdef OLDVERSION
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int la = 0;
        int lb = 0;
        int sizeA = A.size();
        int sizeB = B.size();
        int res = 0;

        if (!sizeA || !sizeB) return res;

        while (la < sizeA) {
            while (lb < sizeB) {
                //find first equal
                if (A[la] == B[lb]) {
//                    cout <<"A[la] == B[lb]     "<< A[la]<< "=="<< B[lb]<<endl;
                    int ra = la + 1;
                    int rb = lb + 1;
                    int count = 1;
                    while ((ra < sizeA) && (rb < sizeB)) {
                        if (A[ra] == B[rb]) {
//                            cout << "-----A[ra] == B[rb]     "<<A[ra]<<"=="<<  B[rb]<<endl;
                            count++; ra++; rb++;
                        } else {
                            //if (res < count) {
                              //  res = count;
                                //cout <<"Res = "<<res<<endl;
                            //}
                            break;
                        }
                    }
                    if (res < count) res = count;
//                    cout<<"Res = "<<res<<endl;
                    //lb = rb;
                } //else
                lb++;
            }
//            cout << "================================="<<endl;
            lb = 0;
            la++;
        }
        cout<<"Res = "<<res<<endl;
        return res;
    }
};
#endif

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //int la = 0;
        //int lb = 0;
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

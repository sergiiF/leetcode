#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int size = A.size()*B.size()*C.size()*D.size();
        if (!size) return 0;
        unordered_map<int,int> axb;
        int count = 0;
        for (int a = 0; a < A.size(); ++a) {
            for (int b = 0; b < B.size(); ++b) { 
                ++axb[A[a]+B[b]];
            }
        }
        for (int c = 0; c < C.size(); ++c) {
            for (int d = 0; d < D.size(); ++d) {
                int cxd = -(C[c]+D[d]);
                if (axb.find(cxd)!= axb.end()) {
                    count+=axb[cxd];
                }
            }
        }
        return count;
    }
};



int main () {
/*
    vector <int> A = {1,2};
    vector <int> B = {-2,-1};
    vector <int> C = {-1,2};
    vector <int> D = {0,2};
*/
    vector <int> A = {-1, -1};
    vector <int> B = {-1, 1};
    vector <int> C = {-1, 1};
    vector <int> D = {1, -1};

    Solution s;
    cout<< s.fourSumCount(A, B,C,D)<<endl;
}
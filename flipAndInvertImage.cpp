/*
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

*/
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>>::iterator it = A.begin();
        while (it != A.end()) {
            reverse(it->begin(),it->end());
            vector<int>::iterator i = it->begin();
            while (i != it->end()) {
                if (*i) *i = 0;
                else *i = 1;
            }
            it++;
        }
        return A;
    }
};

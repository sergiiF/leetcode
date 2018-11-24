#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() <2 || matrix.front().size() <2) 
            return;
        //for each row, rotate each element. ++row, ++start_col, --end_col
        int start = 0;
        int end = matrix.front().size() - 1;
        int row = 0;
        int last = matrix.size() - 1;
        while (start< end) {
            for (int col = start; col < end; ++col) {
                vector<vector<int>> rowsncols{{col, last - row}, {last - row, last - col}, {last - col, row}, {row, col}};
                int moved = matrix[row][col];
                for (auto point : rowsncols) {
                    swap (moved, matrix[point[0]][point[1]]);
                }
            }
            ++row;
            ++start;
            --end;
        }    
    }
};



int main() {
    //vector<vector<int>> matrix {{ 5, 1, 9,11}, {2, 4, 8,10}, {13, 3, 6, 7}, {15,14,12,16}};
    vector<vector<int>> matrix {{1,2,3}, {4,5,6}, {7,8,9}};
    for (auto row: matrix) {
        for (auto cell : row) {
            cout<<cell<<" ";
        }
        cout<<endl;
    }
     cout<<endl;
      cout<<endl;
/* rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
    Solution s;
    s.rotate(matrix);

    for (auto row: matrix) {
        for (auto cell : row) {
            cout<<cell<<" ";
        }
        cout<<endl;
    }

}
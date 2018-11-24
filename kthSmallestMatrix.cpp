#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;


class Solution {
public:
    /*
    1  5  10
    2  6  11
    3  7  12
    */
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix.front().empty()) 
            return -1;
        priority_queue<int> pq;
        for (int row = 0; row < matrix.size(); ++row) {
            if (pq.size() == k && matrix[row][0] >= pq.top())
                break;
            for (int col = 0; col < matrix.front().size(); ++col) {
                if (pq.size() == k && matrix[row][col] >= pq.top())
                    break;
                if (pq.size() == k)
                    pq.pop();
                pq.push(matrix[row][col]);
            }
        }
        return pq.top();
    }

};


int main() {
    //vector<vector<int>> matrix {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> matrix {{1,5,10}, {2,6,11}, {3,7,12}};
    int k = 3;

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

    cout<<k<<"th element = "<<  s.kthSmallest(matrix, k)<< endl;

}
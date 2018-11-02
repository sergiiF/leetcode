#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <iterator>
using namespace std;



class Solution {
public:
    void printGrid(vector<vector<int>>& grid) {
        for (auto x : grid) {
            copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "));
            cout<<endl;
        }
    }

    int uniquePaths(int m, int n) {
        if((m == 0) ||(n == 0)) return 0;
        vector<vector<int>> vec(n, vector<int>(m));
        //vec.size() = rows = n
        //vec[0].size() = columns = m

        //fill 1st row &first column with '1'
        //calc every other cell as sum of left end upper cell
        for (int i = 0; i < m; ++i) {
            vec[0][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            vec[i][0] = 1;
        }
        for (int row = 1; row < n; ++row) {
            for (int column = 1; column < m; ++column) {
                vec[row][column] = vec[row - 1][column] + vec[row][column -1];
            }
        }
        return vec[n-1][m-1];
    }
};



int main() {
    Solution s;
    /*
    vector<vector<int>> vec = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
};
*/
//vector<vector<int>> vec = {{1,2,5},{3,2,1}};
    cout<<s.uniquePaths(7,3)<<endl;
}

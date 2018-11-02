#include <vector>
#include <iostream>
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



    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if (!rows || !cols) return 0;

        printGrid(obstacleGrid);

        //invert grid
        //process first row and column
        obstacleGrid[0][0] = !obstacleGrid[0][0];
        for (int col = 1; col < cols; ++col) {
            obstacleGrid[0][col] = !obstacleGrid[0][col];
            obstacleGrid[0][col] &= obstacleGrid[0][col - 1];
        }

        printGrid(obstacleGrid);

        for (int row = 1; row < rows; ++row) {
            obstacleGrid[row][0] = !obstacleGrid[row][0];
            obstacleGrid[row][0] &= obstacleGrid[row - 1][0];
        }

        printGrid(obstacleGrid);

        //process all other cells
        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (obstacleGrid[row][col]) obstacleGrid[row][col] = !obstacleGrid[row][col];
                else obstacleGrid[row][col] = obstacleGrid[row -1][col] + obstacleGrid[row][col-1];
            }
        }
        printGrid(obstacleGrid);

        return obstacleGrid[rows - 1][cols -1];

    }
};


int main() {
    Solution s;
    /*
    vector<vector<int>> vec = {
    {0,0,0},
   {0,1,0},
   {0,0,0}
};
*/
vector<vector<int>> vec = {{0},{0}};
    cout<<s.uniquePathsWithObstacles(vec)<<endl;
}

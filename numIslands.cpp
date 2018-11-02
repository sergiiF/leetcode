

#include <vector>
#include <queue>
#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;

class Solution {
public:
    int numIslands1(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;

        int max_isle= 1;
        for (int row = 0; row < grid.size(); ++row) {
            for (int column = 0; column < grid[0].size(); ++column) {
                if (grid[row][column]!= '0') {
                    //if there is connected isle mark as that isle
                    //else start new isle
                    char connectedIsle = getConnectedIsle(grid, row, column);
                    if (connectedIsle != '0') grid[row][column] = connectedIsle;
                    else  grid[row][column] =  ++max_isle + '0';
                    // grid[row][column] = (connectedIsle != '0') ? connectedIsle : ++max_isle;
                }
            }
        }
        return max_isle -1;
    }
    char getConnectedIsle(vector<vector<char>>& grid, int row, int column) {
        if (row) {
            if (grid[row -1][column] > '1') {
                return grid[row -1][column];
            }
        }
        if (column) {
            if (grid[row][column -1] > '1') {
                return grid[row][column -1];
            }
        }
        return '0';
    }

    struct Point {
        int row;
        int column;
        Point(int r =0, int c = 0):row(r), column(c){}
    };
    int numIslands(vector<vector<char>>& grid) {
        int rows;
        int columns;
        if (!(rows = grid.size()) || !(columns = grid[0].size())) return 0;
  
        const Point offs[4] = {{-1,0},{1,0},{0,-1},{0,1}};
        stack<Point> isle;
        int isles_count = 0;
        //Point cur_point;

        for (int row = 0; row < grid.size(); ++row) {
            for (int column =  0; column < grid[0].size(); ++column) {
                if (grid[row][column] == '1') {
                    Point isle_point {row, column};
                    isle.push(isle_point);
                    grid[row][column] = '2';
                    while (!isle.empty()) {
                        isle_point = isle.top(); isle.pop();
                        for (auto adj_point : offs) {
                            int tmp_row = isle_point.row + adj_point.row;
                            int tmp_column = isle_point.column + adj_point.column;
                            if (tmp_row >= 0 && tmp_row < rows && tmp_column >=0 && tmp_column < columns && grid[tmp_row][tmp_column] == '1') {
                                isle.push(Point(tmp_row, tmp_column));
                                grid[tmp_row][tmp_column] = '2';
                            }
                        }
                    }
                    ++isles_count;
                }
            }
        }
        return isles_count;
    }
};

int main () {
    //vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','0','0','1'}};
    //vector<vector<char>> grid{{'1','0','0'},{'0','0','0'},{'0','0','0'}};
//[["1","1","1","1","1","1"],["1","0","0","0","0","1"],["1","0","1","1","0","1"],["1","0","0","0","0","1"],["1","1","1","1","1","1"]]
    //vector<vector<char>> grid{};
    vector<vector<char>> grid{{'1','1','1','1','1','1'},{'1','0','0','0','0','1'},{'1','0','1','1','0','1'},{'1','0','0','0','0','1'},{'1','1','1','1','1','1'}};

    Solution s;
    cout <<s.numIslands(grid)<<endl;
}

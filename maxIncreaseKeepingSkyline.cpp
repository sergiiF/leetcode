#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;



class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) return 0;

        vector<int> side;
        vector<int> top;

        int sum = 0;
        //calc max for sides and top&bottom
        for (auto row: grid) {
            side.push_back(getMax(row));
        }
        for (int column = 0; column < grid.front().size(); ++column) {
            top.push_back(getMax(column, grid));
        }
        //for each cell get min from corresponding side or top, store difference
        for (int row = 0; row < grid.size(); ++row) {
            for (int column = 0; column < grid.front().size(); ++column) {
                int stored = grid[row][column];
                grid[row][column] = min(side[row], top[column]);
                sum += grid[row][column] - stored;
            }
        }
        return sum;
    } 
private:
    int getMax(vector<int> vec) {
        int res = vec[0];
        for(int cell = 1; cell < vec.size(); ++cell) {
            res = vec[cell] > res ? vec[cell] : res;
        }
        return res;
    }
    int getMax(int col,const vector<vector<int>>& grid) {
        int res = grid[0][col];
        for (int row = 1; row < grid.size(); ++ row) {
            res = grid[row][col] > res ? grid[row][col] : res;
        }
        return res;
    }
};

int main() {
    vector<vector<int>> graph {{3,0,8,4}, {2,4,5,7}, {9,2,6,3}, {0,3,1,0}};
    //vector<vector<int>> graph {{1},{0,3},{3},{1,2}};
    Solution s;
    cout<< s.maxIncreaseKeepingSkyline(graph)<<endl;
}
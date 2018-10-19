#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <iterator>
using namespace std;

struct Point{
    int line;
    int col;
};

class GridPath {
public:
    GridPath(int n, int m, const vector<vector<int>>* grid):dim{n, m},path{grid} {
        m_sum = (*path)[0][0];
    };
    //GridPath(const GridPath& copy) path = copy.path, dim = copy.dim,
    //                        cur_point = copy_cur_point, sum = copy.sum{};
    void moveDown();
    void moveRight();
    bool shouldSplit() {return canMoveDown() && canMoveRight();};
    bool canMoveDown();
    bool canMoveRight();
    //GridPath& split() {return GridPath(*this);};
    int sum() const { return m_sum;}
    bool completed() {return cur_point.col == dim.col - 1 and cur_point.line == dim.line - 1;}
    //
    // static vector<vector<int>> path;

private:
    int m_sum = 0;
    const vector<vector<int>> *path;
    Point dim;
    Point cur_point = {0,0};
};

bool GridPath::canMoveDown(){
    return cur_point.line < dim.line-1;
}

bool GridPath::canMoveRight() {
    return cur_point.col < dim.col-1;
}

void GridPath::moveDown(){
    cout<<"moving down\n";
    m_sum += (*path)[++cur_point.line][cur_point.col];
}

void GridPath::moveRight(){
    cout<<"moving right\n";
    m_sum += (*path)[cur_point.line][++cur_point.col];
}

class Solution {
public:
    int minPathSum1(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<GridPath> incomplete_pathes;
        queue<GridPath>::size_type max_queue_size = 0;
        GridPath min_path(n, m, &grid);

        incomplete_pathes.push(GridPath(n, m, &grid));
        while (!incomplete_pathes.empty()) {
            cout<<"pop path from queue\n";
            max_queue_size = max(max_queue_size, incomplete_pathes.size());
            GridPath cur_path = incomplete_pathes.front();
            incomplete_pathes.pop();

            while (!cur_path.completed()/*path is completed*/) {
                if (min_path.completed() && (cur_path.sum() > min_path.sum()) ){
                    cout<<"sum ecxeeded, discard path\n";
                    break;
                }
                if(cur_path.shouldSplit()) {
                    cout<<"splitting pathes\n";
                    GridPath new_path {cur_path};
                    new_path.moveRight();
                    incomplete_pathes.push(new_path);

                    cur_path.moveDown();
                } else if(cur_path.canMoveDown()){
                    cur_path.moveDown();
                } else {
                    cur_path.moveRight();
                }
            }
            if (!cur_path.completed()) {
                cout<<"path is incomplete, discard\n";
                continue;
            }
            cout<<"path completed. Sum: "<<cur_path.sum()<<endl;
            if (!min_path.completed() || cur_path.sum() < min_path.sum()) {
                cout<<"Min sum = "<<min_path.sum()<<" current sum = "<<cur_path.sum()<<endl;
                swap(cur_path, min_path);
                cout<<"swapped. Now min sum = "<<min_path.sum()<<endl;
            }
        }
        cout<<"max queue size: "<<max_queue_size<<endl;
        return min_path.sum();
    }

    void printGrid(vector<vector<int>>& grid) {
        for (auto x : grid) {
            copy(x.begin(), x.end(), ostream_iterator<int>(cout, " "));
            cout<<endl;
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        //vector<vector<int>> (grid.size(), vector<int>(grid[0].size()));
        printGrid(grid);

        if(grid.empty()||grid[0].empty()) return 0;
        int rows = grid.size();
        int columns = grid[0].size();
        //init grid[0][x] - first row
        for(int i = 0, sum = 0; i < columns; ++i) {
            grid[0][i] = sum +=grid[0][i];
        }

        cout<<endl<<"after 1 row calculating: "<<endl;
        printGrid(grid);
        //init grid[x][0]
        for (int i = 0, sum = 0; i< rows; ++i) {
            grid[i][0] = sum +=grid[i][0];
        }

        cout<<endl<<"after 1 column calculating: "<<endl;
        printGrid(grid);

        for(int i = 1; i < rows; ++i) {
            for (int j = 1; j < columns ; ++j) {
                cout<<"calc [i][j] "<<i<<" : "<<j<<endl;
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        cout<<endl<<"after all matrix calculating: "<<endl;
        printGrid(grid);

        return grid[rows-1][columns-1];
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
vector<vector<int>> vec = {{1,2,5},{3,2,1}};
    cout<<s.minPathSum(vec)<<endl;
}

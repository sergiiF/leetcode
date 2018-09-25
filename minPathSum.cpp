#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

class GridPath {
public:
    GridPath(int n, int m, const vector<vector<int>>* grid):dim{n, m},path{grid} {};
    //GridPath(const GridPath& copy) path = copy.path, dim = copy.dim,
    //                        cur_point = copy_cur_point, sum = copy.sum{};
    void moveDown();
    void moveRight();
    bool shouldSplit() {return canMoveDown() && canMoveRight();};
    bool canMoveDown();
    bool canMoveRight();
    //GridPath& split() {return GridPath(*this);};
    int sum() const { return m_sum;}
    bool completed() {return cur_point == dim;}
    //
    // static vector<vector<int>> path;

private:
    int m_sum = 0;
    const vector<vector<int>> *path;
    vector<int> dim;
    vector<int> cur_point = {0,0};
};

bool GridPath::canMoveDown(){
    return cur_point[0] < dim[0];
}

bool GridPath::canMoveRight() {
    return cur_point[1] < dim[1];
}

void GridPath::moveDown(){
    cout<<"moving down/n";
    m_sum += (*path)[++cur_point[0]][cur_point[1]];
}

void GridPath::moveRight(){
    cout<<"moving right/n";
    m_sum += (*path)[cur_point[0]][++cur_point[1]];
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<GridPath> incomplete_pathes;
        GridPath min_path(n, m, &grid);

        incomplete_pathes.push(GridPath(n, m, &grid));
        while (!incomplete_pathes.empty()) {
            cout<<"pop path from queue/n";
            GridPath cur_path = incomplete_pathes.front();
            incomplete_pathes.pop();

            while (!cur_path.completed()/*path is completed*/) {
                if (min_path.sum() && (cur_path.sum() > min_path.sum()) ){
                    cout<<"sum ecxeeded, discard path/n";
                    break;
                }
                if(cur_path.shouldSplit()) {
                    cout<<"splitting pathes/n";
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
                cout<<"path is incomplete, discard/n";
                continue;
            }
            cout<<"path completed/n";
            if (min_path.sum()) {
                cout<<"Min sum = "<<min_path.sum()<<" current sum = "<<cur_path.sum()<<endl;
                if (cur_path.sum() < min_path.sum()) {
                    swap(cur_path, min_path);
                    cout<<"swapped. Now min sum = "<<min_path.sum()<<endl;
                }
            }
        }
        return min_path.sum();
    }
};


int main() {
    Solution s;
    vector<vector<int>> vec = {
  {1,3,1},
  {1,5,1},
  {4,2,1}
};

    cout<<s.minPathSum(vec)<<endl;
}

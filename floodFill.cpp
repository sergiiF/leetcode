#include <vector>
#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

template <typename T>
void vector_print(const string& msg, const vector<T>& v) {
    cout<<msg<<endl;
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout<<endl;
}


class Solution {
public:
    struct Point {
        Point(int r = 0, int c = 0):row(r), column(c) {}

        int row;
        int column;
    
    Point operator+(Point const &p) {
        Point res;
        res.row = row + p.row;
        res.column = column + p.column;
        return res;
    }
    
    };
/*
    Point operator+(Point const &p1, Point const &p2) {
        Point res;
        res.row = p1.row + p2.row;
        res.column = p1.column + p2.column;
        return res;
    }
*/
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty()) return image;

        const int oldColor = image[sr][sc]; 
        if(oldColor == newColor) return image;

        const int max_row = image.size() - 1;
        const int max_column = image.front().size() - 1;

        Point nb[4]{{-1,0}, {1,0}, {0, -1}, {0, 1}};

        queue<Point> forFill;
        forFill.push({sr,sc});

        while (!forFill.empty()) {
            Point cur_point = forFill.front(); forFill.pop();
            image[cur_point.row][cur_point.column] = newColor;
            
            for (Point adj_point : nb) {
                adj_point = cur_point + adj_point;
                if (0 <= adj_point.row && adj_point.row <= max_row && 
                    0 <= adj_point.column && adj_point.column <= max_column && 
                    image[adj_point.row][adj_point.column] == oldColor) {
                        forFill.push({adj_point.row, adj_point.column});
                    }
            }
        }
        return image;
    }
};

int main () {
    vector<vector<int>> vec = {{0,0,0},{0,1,1}};

    Solution s;
    vec = s.floodFill(vec, 1,1,1);

    for (auto v : vec)
        vector_print("", v);
}

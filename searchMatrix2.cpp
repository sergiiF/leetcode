#include <vector>
#include <iostream>
#include <utility>

using namespace std;


class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //pair<min_row, max_row> = cropRows();
        //for each row
            //find target

        pair <int, int> range = cropRows(matrix, target);
        cout<<"from "<<range.first<<" to "<<range.second<<endl;

        for (int i = range.first; i <= range.second; ++i) {
            if (findTarget(matrix[i], target))
                return true;
        }
        return false;
    }
private:
    int cropMaxRow(vector<vector<int>>& matrix, int low, int hi, int target) {
        int mid;
        while (low < hi) {
            mid = (hi + low) / 2 + ((hi + low) & 1);
            if (mid == low) return hi;
            if (matrix[mid][0] <= target) {
                low = mid;
            } else {
                hi = mid - 1;
            }
        }
        return low;
    }

    int cropMinRow(vector<vector<int>>& matrix, int low, int hi, int target) {
        int mid;
        int last = matrix[0].size() - 1;
        while (low < hi) {
            mid = (hi + low) / 2;
            //if (mid == low) break;
            if (matrix[mid][last] < target) {
                low = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }



    pair<int, int> cropRows(vector<vector<int>>& matrix, int target) {
        //if matrix
        int max_row = cropMaxRow(matrix, 0, matrix.size() - 1, target);
        int min_row = cropMinRow(matrix, 0, max_row, target);

        return pair<int,int> (min_row, max_row);
    }

    bool findTarget(vector<int> vec, int target) {
        int low = 0;
        int hi = vec.size() - 1;
        int mid;
        while (low <= hi) {
            mid = (hi + low) / 2;
            if (vec[mid] == target) {
                return true;
            } else if(vec[mid] < target) {
                low = mid + 1;
            } else {
                hi = mid -1;
            }
        }
        return false;
    }
};



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ((!matrix.size()) || (!matrix[0].size())) return false;

        int m = matrix.size() - 1;
        int n = 0;
        while ((n < matrix[0].size()) && (m >= 0)) {
            cout<<" now m= "<<m<<" n= "<<n<<endl;
            if (matrix[m][n] == target) return true;
            while ((m >= 0) && (matrix[m][n] > target)) --m;
            while ((m >= 0) &&(n < matrix[0].size()) && (matrix[m][n] < target)) ++n;
        }
        return false;
    }
};

int main () {
    vector<vector<int>> matrix = {
                                  {1,   4,  7, 11, 15},
                                  {2,   5,  8, 12, 19},
                                  {3,   6,  9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}
                              };


    vector<vector<int>> matrix1 = {{1,1}};
    Solution s;

    cout<<"Find 5: "<<s.searchMatrix(matrix1, 0)<<endl;
    cout<<"Find 200: "<<s.searchMatrix(matrix, 200)<<endl;


 }

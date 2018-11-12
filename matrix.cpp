/*
Please use this Google doc to code during your interview. To free your hands for coding, we recommend that you use a headset or a phone with speaker option.

Question:
We have an NxN matrix of integer numbers and we want to compute the minimum value of each WxW window, where W<=N. The return value is also a matrix, containing for each window the min value computed for it.

For example,

Input constraints: N = 4, W = 2,
Input Matrix:

/                  \  
|   1   6   3   8  |         
|   5   2   7   4  |           
|   9  10  15  12  |
|  13  14  16  11  |
\                  /

So for each 2x2 by window we want the mins from

/        \   /        \      /          \
|  1  6  |   |  6  3  |  ... |  15  12  |
|  5  2  |   |  2  7  |  ... |  16  11  |
\        /   \        /      \          /

And the final result will be

/             \
|  1   2   3  |
|  2   2   4  |
|  9  10  11  |
\             /

Please write a function to do the calculation.
Please also write some unit-tests for your code.

*/
#include <vector>
#include <climits>

using namespace std;

int  calculateMinInMatrix(vector<vector<int>> origMatrix,int startRow, int startColumn, int nestedMatrixSize ) {
int min = INT_MAX;
    for (int row = startRow; row < startRow + nestedMatrixSize; ++row) {
        for (int column = startColumn; column < startColumn + nestedMatrixSize; ++ column) {
            if(origMatrix[row][column] < min)
                min = origMatrix[row][column];
        }
    }
    return min;
}


vector<vector<int>> createMinMatrix(vector<vector<int>> origMatrix, int nestedMatrixSize) {
    if (origMatrix.empty())
        return origMatrix;
    vector <vector<int>> minMatrix;
    if (nestedMatrixSize > origMatrix.size() || nestedMatrixSize > origMatrix.front().size() || origMatrix.size() != origMatrix.front().size())
        return minMatrix;


/*
for each element in rows [0, size()-1) create nested matrix
    calc min
    add min to result matrix
*/
    int rows = origMatrix.size();
    int columns = origMatrix.front().size();
    for (int row = 0; row <= rows - nestedMatrixSize; ++row) {
        vector<int> minMatrixRow;
        for (int column = 0; column <= columns - nestedMatrixSize; ++ column) {
            int minValue = calculateMinInMatrix(origMatrix, row, column,nestedMatrixSize );
            minMatrixRow.push_back(minValue);
        }
        minMatrix.push_back(minMatrixRow);
    }
    return minMatrix;
    
}

int findMinInHorizontalSlice(vector<int> vec, int start,int end) {
    while (start < end) {
        if (vec[start] < vec[end])
            vec[end] = vec[start];
        ++start;
    }
    return vec[end];
}

void findMinInVerticalSlice(vector<vector<int>>&  matrix, int column, int start,int end) {
    while (start < end) {
        if (matrix[start][column] > matrix[end][column]) {
            matrix[start][column] = matrix[end][column];
            --end;
        }
        return;
    }
}

/* don't work properly*/
vector<vector<int>> createMinMatrixOptimized(vector<vector<int>> origMatrix, int nestedMatrixSize) {
    if (origMatrix.empty())
        return origMatrix;
    vector <vector<int>> minMatrix;
    int rows = origMatrix.size();
    int columns = origMatrix.front().size();

    for (int row = 0; row <= rows - nestedMatrixSize; ++row) {
        vector<int> minMatrixRow;
        int start = 0;
        int end  = nestedMatrixSize - 1;
        while (end < columns) {
            minMatrixRow.push_back(findMinInHorizontalSlice(origMatrix[row], start, end));
            ++start;
            ++end;
        }
        minMatrix.push_back(minMatrixRow);
    }
    for (int column = 0; column <=columns - nestedMatrixSize; ++column) {
        int start = 0;
        int end  = nestedMatrixSize - 1;
        while (end < rows) {
            findMinInVerticalSlice(origMatrix,column, start, end);
            ++start;
            ++end;
        }

    }
    //minMatrix.pop_back();
    return minMatrix;

}


vector<vector<int>> createMinMatrixOptimized(vector<vector<int>> origMatrix, int nestedMatrixSize) {
    int rows = origMatrix.size();
    int columns = origMatrix.front().size();
    vector <vector<int>> minMatrix {};
}

int main() {

    vector<vector<int>> matrix = {{1, 6, 3, 8}, {5, 2, 7, 4}, {9, 10, 15, 12}, {13, 14, 16, 11}};
    vector<vector<int>> result  = createMinMatrix(matrix, 3);
    vector<vector<int>> resultOptimized  = createMinMatrixOptimized(matrix, 3);
int finale = 1;
}




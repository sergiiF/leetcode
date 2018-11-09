#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int transfer = 1;
        for (int i = digits.size() -1; i >= 0; --i) {
            int sum = digits[i] + transfer;
            if (sum <10) {
                digits[i] = sum;
                transfer = 0;
            } else {
                digits[i] = sum - 10;
            }
        }
        if (transfer)
            digits.insert(digits.begin(), transfer);
       return digits;
    }
};

int main (){
    vector<int> vec {9,9,9,9,9,9,9,9,9};
    Solution s;
    vec = s.plusOne(vec);
    for(int num:vec) {
        cout<<num<<',';
    }
    cout<<endl;
}
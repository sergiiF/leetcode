#include <vector>
#include <stack>
#include <string>
#include <assert.h>
#include <iostream>
#include <algorithm>
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
    vector<int> dailyTemperatures1(vector<int>& T) {
        if (T.empty()) return T;
        
        for (int day = 0; day < T.size(); ++day) {
            int tmp = day + 1;
            while ((tmp < T.size() ) && (T[day] >= T[tmp])) ++tmp;
            
            T[day] = tmp < T.size() ? tmp - day : 0;
        }
        return T;
    }

    struct StackedDays{
        int day;
        int temp;
    };

    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return T;
        stack<StackedDays> st;
        
        for (int day = 0; day < T.size(); ++day) {
            while (!st.empty() && st.top().temp < T[day]) {
                T[st.top().day] = day - st.top().day;
                st.pop();
            }
            st.push({day, T[day]});
        }
        while (!st.empty()) {
            T[st.top().day] = 0;
            st.pop(); 
        }
        return T;
    }
};


int main () {
    vector<int> temps = {73, 80, 75, 71, 69, 72, 76, 73};
    vector_print("Init: ", temps);
    Solution s;
    temps = s.dailyTemperatures(temps);
    vector_print("Res: ", temps);

}
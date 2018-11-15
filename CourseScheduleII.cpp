#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses == 0) return res;
        //populate vector
        vector<vector<int>>graph (numCourses);
        vector<int> visited(numCourses, 0);
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            ++visited[p.first];
        }
        stack<int> st;
        for (int i = 0; i < visited.size(); ++i) {
            if (visited[i] == 0) {
                st.push(i);
            }
        }
        while (!st.empty()) {
            int course = st.top(); st.pop();
            res.push_back(course);
            for (auto child : graph[course]) {
                if (--visited[child] == 0)
                    st.push(child);
            }
        }
        for (auto x: visited) {
            if (x > 0) {
                res.clear();
                break;
            }
        }
        return res;
    }
};



int main () {
    vector<pair<int, int>> nums = {{1,0}, {0,1}};
    int num = 2;


    //vector<pair<int, int>> nums = {{1,0},{2,0},{3,1},{3,2}};
    //int num = 4;


    //vector<pair<int, int>> nums = {{1,0},{1,2},{0,1}};
    //int num = 3;

    Solution s;
    vector<int> res = s.findOrder(num, nums);

    for (auto x: res) {
        cout<<x<< " ";
    }
    cout<<endl;


    cout<<endl;
}

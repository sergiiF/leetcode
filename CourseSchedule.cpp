#include <vector>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0 || prerequisites.empty()) return true;
        vector <int> dependencies(numCourses, 0);
        vector <vector<int>> childrenGraph(numCourses);
        //build adjacency lists of dependent
        for (auto p : prerequisites) {
            ++dependencies[p.first];
            childrenGraph[p.second].push_back(p.first);
        }
        stack <int> st;
        for (int i = 0; i < numCourses; ++i) {
            if (dependencies[i] == 0) {
                st.push(i);
            }
        }

        while (!st.empty()) {
            int id = st.top(); st.pop();
            for (auto child: childrenGraph[id]) {
                if (--dependencies[child] == 0) 
                    st.push(child);
            }
        }

        for (auto item: dependencies) {
            if (item != 0) return false;
        }
        return true;
    }

};

int main() {
    //vector<pair<int, int>> nums = {{1,0}, {0,1}};
    //int num = 2;


    vector<pair<int, int>> nums = {{1,0},{2,0},{3,1},{3,2}};
    int num = 4;


    //vector<pair<int, int>> nums = {{1,0},{1,2},{0,1}};
    //int num = 3;

    Solution s;
    bool res = s.canFinish(num, nums);
    string r = (res)?"true":"false";
    cout<<r<<endl;
}
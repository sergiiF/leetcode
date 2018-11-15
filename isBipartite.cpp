#include <vector>
#include <iostream>
#include <climits>
#include <queue>
using namespace std;


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty()) return true;
        vector<int> groups(graph.size(), 0);
        for (int i = 0; i< groups.size(); ++i) {
            if (groups[i] == 0) {
                groups[i] = 1;
                queue<int> vertexes;
                vertexes.push(i);
                while (!vertexes.empty()) {
                    int vertex = vertexes.front();
                    vertexes.pop();

                    int next = -1* groups[vertex];
                    //check all adj are in diff group
                    for (auto adj: graph[vertex]) {
                        if (groups[adj] == 0) {
                            groups[adj] = next;
                            vertexes.push(adj);
                        } else if (groups[adj] != next) {
                            return false;
                        }
                    }
                }

            }
        }
        return true;
    }
};


int main() {
    vector<vector<int>> graph {{1,2,3}, {0,2}, {0, 1,3}, {0,2}};
    //vector<vector<int>> graph {{1},{0,3},{3},{1,2}};
    Solution s;
    cout<< s.isBipartite(graph)<<endl;
}
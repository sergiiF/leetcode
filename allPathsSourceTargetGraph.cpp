#include <vector>
#include <string>
#include <climits>
#include <map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;



class Solution {
public:
        //find path from 0 to N-1
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph.empty()) return graph;
        int target = graph.size() -1;

        vector<vector<int>> result;
        vector<int> cur_path;
        dfs(0, target, graph, cur_path, result);
        return result;
    }

    private:
    void dfs(int i, int target, vector<vector<int>>& graph, vector<int>& cur_path, vector<vector<int>> &pathes) {
        cur_path.push_back(i);
        if (i == target) {
            pathes.push_back(cur_path);
            return;
        }
        for (int vertex: graph[i]) {
            dfs(vertex, target, graph, cur_path, pathes);
        }
        cur_path.pop_back();
    }
};



int main() {
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> result;
    Solution s;
    result = s.allPathsSourceTarget(graph);
    
}
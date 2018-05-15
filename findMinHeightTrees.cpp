#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;


class Solution {
    map<pair<int, int>, int> cache;
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;

        vector<vector<int>> vertexes(n);
        int minHeight = n;
        //create array of vertexes
        for (int i = 0; i < edges.size(); i++) {
            vertexes[edges[i].first].push_back(edges[i].second);
            vertexes[edges[i].second].push_back(edges[i].first);
        }

        //for each vertex calc height
        for (int i = 0; i < n; i++) {
            int height = calcHeight(i, vertexes, -1);
            //cout <<"for "<<i<< " height = "<<height<<endl;
            if (minHeight > height) {
                res.clear();
                res.push_back(i);
                minHeight = height;
            } else if (minHeight == height) {
                res.push_back(i);
            }
        }

        return res;

    }

    int calcHeight(int root, vector<vector<int>>& v, int parent) {
        int max_h = 1;
        for (int i = 0; i < v[root].size(); i++) {
            int vertex_to = v[root][i];
            if (vertex_to == parent) continue;
            auto it = cache.find(pair<int, int>(root, vertex_to));
            if (it == cache.end()) {
                int h = calcHeight(vertex_to, v, root) + 1;
                cache[pair<int, int>(root, vertex_to)] = h;
                max_h = max(max_h, h);
            } else {
                max_h = max(max_h, it->second);
            }
        }
        //cout << parent << "->"<< root << ", max_h: "<< max_h << endl;
        return max_h;
    }
};

/*class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;

        vector<vector<int>> vertexes(n);
        int minHeight = n;
        //create array of vertexes
        for (int i = 0; i < edges.size(); i++) {
            vertexes[edges[i].first].push_back(edges[i].second);
            vertexes[edges[i].second].push_back(edges[i].first);
        }

        //for each vertex calc height
        for (int i = 0; i < n; i++) {
            int height = calcHeight(i, n, vertexes);
            cout <<"for "<<i<< " height = "<<height<<endl;
            if (minHeight > height) {
                res.clear();
                res.push_back(i);
                minHeight = height;
            } else if (minHeight == height) {
                res.push_back(i);
            }
        }

        return res;

    }

    int calcHeight(int root, int n, vector<vector<int>>& v) {
        queue<int> q;
        bool marked[n] = {0};
        int height = 0;

        q.push(root);
        marked[root] = true;

        while (!q.empty()) {
            int size = q.size();
            if (size) height ++;

            while (size) {

                int node = q.front();
                q.pop();
                size--;
                bool leaf = false;
                cout<<"Node "<<node<<" childs: ";
                for (int i = 0; i < v[node].size(); i++) {
                    cout<<v[node][i];
                    if ((v[node].size() == 1) && (marked[v[node][i]] == true))
                        leaf = true;
                    if (false == marked[v[node][i]]) {
                        marked[v[node][i]] = true;
                        q.push(v[node][i]);
                    }
                }
                cout<<endl;
                if (leaf) return height;
            }
        }
        return height;
    }
};
*/
int main () {
    //n = 4, edges = [[1, 0], [1, 2], [1, 3]]
    int arr[][] = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]];
    vector<int> res;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(1,0));
    edges.push_back(make_pair(1,2));
    edges.push_back(make_pair(1,3));

    Solution s;

    res = s.findMinHeightTrees(4, edges);
    for (int i = 0; i < res.size(); i++) {
        cout<< res[i]<<" ";
    }
    return 0;
}


/*
# Before Sergii intruded
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;

        vector<vector<int>> vertexes(n);
        int minHeight = n;
        //create array of vertexes
        for (int i = 0; i < edges.size(); i++) {
            vertexes[edges[i].first].push_back(edges[i].second);
            vertexes[edges[i].second].push_back(edges[i].first);
        }

        //for each vertex calc height
        for (int i = 0; i < n; i++) {
            int height = calcHeight(i, n, vertexes);
            //cout <<"for "<<i<< " height = "<<height<<endl;
            if (minHeight > height) {
                res.clear();
                res.push_back(i);
                minHeight = height;
            } else if (minHeight == height) {
                res.push_back(i);
            }
        }

        return res;

    }

    int calcHeight(int root, int n, vector<vector<int>>& v) {
        queue<int> q;
        bool marked[n] = {0};
        int height = 0;

        q.push(root);
        marked[root] = true;

        while (!q.empty()) {
            int size = q.size();
            if (size) height ++;

            while (size) {
                int node = q.front();
                q.pop();
                size--;
                int childCount = v[node].size();
                for (int i = 0; i < childCount; i++) {
                    if (!marked[v[node][i]]) {
                        marked[v[node][i]] = true;
                        q.push(v[node][i]);
                    }
                }
            }
        }
        return height;
    }
};
*/

/*
    int calcHeight(int root, vector<vector<int>>& v) {
        int height = 0;
        int min = MAX_INT;
        for (int i = 0; i < v[root].size(); i++) {
            height = calcHeight(root, v[root][i], v);
            min = height < min ? height : min;
        }

        return min;
    }

    int calcHeight(int root, int vert, vector<vector<int>>& v) {
        if (pos)
    }
*/

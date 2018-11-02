#include <vector>
#include <iostream>
#include <queue>

using namespace std;
class Solution {
public:
    bool canVisitAllRooms1(vector<vector<int>>& rooms) {
        if (rooms.empty()) return false;
        bool visited[rooms.size()] = {false};
        dfs(rooms, 0, visited);

        for (auto res: visited)
            if (!res)
                return false; 
        return true;
    }

    void dfs(vector<vector<int>>& rooms, int cur_room, bool* visited) {
        if (visited[cur_room]) return;
        visited[cur_room] = true;

        for (auto neighbor: rooms[cur_room])
            dfs(rooms, neighbor, visited);
        
    }

       bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty()) return false;
        bool visited[rooms.size()] = {false};

        queue<int> wouldVisit;
        wouldVisit.push(0);
        while (!wouldVisit.empty()) {
            int cur_room = wouldVisit.front(); wouldVisit.pop();
            if (!visited[cur_room]) {
                visited[cur_room] = true;
                for (int neighbor: rooms[cur_room]) {
                    wouldVisit.push(neighbor);
                }
            }
        }


        for (auto res: visited)
            if (!res)
                return false; 
        return true;
    }


};


int main () {
    Solution s;
    vector<vector<int>> vec = {{1,3,2},{3,0,1},{2},{0}};
    cout<<s.canVisitAllRooms(vec)<<endl;

}
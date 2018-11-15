#include <vector>
#include <iostream>
#include <climits>
#include <queue>
using namespace std;


class Solution {
public:

class Graph{
public:
    Graph(int s): size(s), adjList(s) {}
    void addEdge(int src, int dst, int cost) {
        adjList[src].push_back(make_pair(cost, dst));
    }

    int getCheapest(int src, int dst, int maxStops) {
       //int cheapest = -1;
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //pair<cost, dst>
        pq.emplace(0,make_pair(src, -1));
        while (!pq.empty()) {
            int city = pq.top().second.first; 
            int cost = pq.top().first;
            int stops =pq.top().second.second;
            pq.pop();
            if (city == dst) return cost;
            for (auto flight: adjList[city]) {
                int curCity = flight.second;
                int curCost = flight.first + cost;
                int curStops = stops + 1;
                if (curStops <= maxStops) { // if cur dst cost in visited > dst.weight + curCity weight
                    //if this stop is dst - remember in cheapest and continue
                    pq.emplace(curCost, make_pair(curCity, curStops));
                }
            }
       }
        //find cheapest in visited
       //return cheapest;
        return -1;
    }

private:
    int size;
    vector<vector<pair<int, int>>> adjList; //pair<cost, dest>

};
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        Graph graph(n);
        for (auto flight: flights) {
            graph.addEdge(flight[0], flight[1], flight[2]);
        }

        return graph.getCheapest(src, dst, K);
    }
};


int main() {
    //vector<vector<int>> edges = {{0,1,100},{1,2,100},{0,2,500}};
    //int n = 3, src =0, dst = 2, k = 0;

    //vector<vector<int>> edges = {{0,1,1},{0,2,5},{1,2,1}, {2,3,1}};
    //int n = 4, src =0, dst = 3, k = 1;

    vector<vector<int>> edges = {{0,1,5},{1,2,5},{0,3,2}, {1,4,1}, {4,2,1}};
    int n = 5, src =0, dst = 2, k = 2;


   Solution s;
   cout<<s.findCheapestPrice(n, edges,src,dst,k) <<endl;

}
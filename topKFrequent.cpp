#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <functional>     // std::greater, less
#include <iostream>
using namespace std;


class Solution {
public:
    class FriquencyComparator {
        public:
        bool operator() (pair<int, int> elem1, pair<int, int> elem2) {
            return elem1.second > elem2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> res;
        if (nums.empty()) return res;
        unordered_map<int,int> elementsFriquency;
        for (int elem: nums) {
            elementsFriquency[elem]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, FriquencyComparator> mostFriquent;
        FriquencyComparator fCmp;
        for (auto pair: elementsFriquency) {
            if (mostFriquent.size() < k) {
                mostFriquent.push(pair);
            } else {
                if (fCmp(pair, mostFriquent.top())) {
                //if (pair.second > mostFriquent.top().second) {
                    mostFriquent.pop();
                    mostFriquent.push(pair);
                }
            }
        }

        while (!mostFriquent.empty()) {
            res.push_back(mostFriquent.top().first);
            mostFriquent.pop();
        }
        return res;
    }
};

int main() {
    vector<int> vec{};
    Solution s;
    vector<int> res = s.topKFrequent(vec, 1);

    for (int num: res) {
        cout<<num<<" ";
    }
    cout<<endl;

}
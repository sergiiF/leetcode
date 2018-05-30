#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define VER2

#ifdef VER1
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res;
        list<int> l(nums2.begin(),nums2.end());

        for (auto i : nums1) {
            list<int>::iterator it;
            if ((it = find(l.begin(), l.end(), i)) != l.end()) {
                res.push_back(i);
                l.erase(it);
            }
        }

        return res;
    }
};

#endif


#ifdef VER2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res;

        if (nums1.empty() || nums2.empty()) return res;

        sort (nums1.begin(), nums1.end());
        sort (nums2.begin(), nums2.end());
        //int size = nums1.size() < nums2.size() : nums1.size() ? nums2.size();
        int i = 0;
        int j = 0;
        while((i < nums1.size()) && (j < nums2.size())) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++; j++;
            } else {
                while ((i < nums1.size()) && (nums1[i] < nums2[j])) i++;
                while ((j < nums2.size())&& (nums2[j] < nums1[i])) j++;
            }
        }

        return res;
    }
};

#endif

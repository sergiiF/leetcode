#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        if (n == 0) return res;
        int fizz = 3;
        int buzz = 5;
        for (int i = 1; i <=n; ++i) {
            string str;
            if (i == fizz || i == buzz) {
                if (i == fizz) {
                    str.append("Fizz");
                    fizz+=3;
                }
                if (i == buzz) {
                    str.append("Buzz");
                    buzz+=5;
                }
            } else {
                str.append(to_string(i));
            }
            res.push_back(str);
        }
        return res;
    }
};
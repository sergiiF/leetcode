#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = nextCharacter(S, S.length());
        int k = nextCharacter(T, T.length());
        while ((i>=0) && (k >=0)) {
            cout<<"i= "<<i<<",k= "<<k<<" Comparing "<<S[i]<<" and "<<T[k]<<endl;
            if (S[i] != T[k]) return false;
            i = nextCharacter(S, i);
            k = nextCharacter(T, k);
        }
        return (i == k);
    }
private:
        int nextCharacter(const string& str, int id) {
            cout<<"nextCharacter("<<id <<")"<< endl;
            if (id == str.length()) {
                id = str.length() - 1;
                if (str[id] != '#') {
                    return id;
                }
            }
            if (str[id] != '#'){
             --id;
         }
            int count = 0;
            while (((str[id] == '#') || count)  && (id >= 0)) {
                if (str[id] == '#') ++count;
                else if (count) --count;
                --id;
            }
            cout<<"Returning id "<<id<<endl;
            return id;
        }



    bool backspaceCompare1(string S, string T) {
        cout<<S<<endl;
        cout<<T<<endl;
        int i = 0;
        for(int j = 0; j < S.length(); ++i,++j) {
            if (S[j] == '#') {
                --i;
                if (j < S.length() - 1) ++j;
            }
            swap(S[i],S[j]);
        }
        cout<<" First: "<<S<<", i= "<<i<<endl;
        int k = 0;
        for(int m = 0; m < S.length(); ++k,++m) {
            if (T[m] == '#') {
                --i;
                if (m < T.length() - 1) ++m;
            }
            swap(T[k],T[m]);
        }
        cout<<" Second: "<<T<<", k= "<<k<<endl;

        bool res = (S.compare(0,i,T,0,k) == 0)?"1":"0";
        return res;
    }
};


int main () {
    Solution s;
    cout<<s.backspaceCompare({"vddd"},{"vddd#d"})<<endl;
}

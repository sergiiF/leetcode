/*
cwd = /a/b
path = ../c/../d/
Output - /a/d

cwd = /a/b/c path = /d/e output = /d/e
cwd = /a/b/c path = ../../../../../../../e output = /e
*/

#include <string>
#include <stack>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class WorkingDirectory {
private:
    string cwd;
public:
    WorkingDirectory(string s = "/"): cwd(s) {};

    void applyPath(string path) {
        vector<string> st_dir = createStack();
        cout<<"stack: ";
        copy(st_dir.begin(), st_dir.end(), ostream_iterator<string>(cout, " "));
        cout<<endl;

        //apply path
        int start = 0, last = path.length();
        int cur = start;
        if (path[start] == '/') st_dir.clear();

        while (start < last) {
            start = skip_slash(path, start);
            string instr = get_token(path, start);

            if (instr.empty()) continue;

            if (instr == "..") {
                if (!st_dir.empty())
                    st_dir.pop_back();
            } else if (!instr.empty()) {
                st_dir.push_back(instr);
            }
        }

        cout<<"new stack: ";
        copy(st_dir.begin(), st_dir.end(), ostream_iterator<string>(cout, " "));
        cout<<endl;

        //set new cwd
        string tmp{};

        for(auto s : st_dir) {
            tmp+='/';
            tmp+=s;
        }
        if (tmp.empty()) tmp+='/';
        //cwd == tmp;
        swap(cwd, tmp);
    }

    const string& getCwd() {
        return cwd;
    }

private:
    vector<string> createStack() {
        vector<string> st{};
        int index = 0, last_id = cwd.length() - 1;

        while (index <= last_id){
            index = skip_slash(cwd, index);
            string token = get_token(cwd, index);
            if (!token.empty()) {
                st.push_back(token);
            }
        }
        /*
        //create stack
        int start_id = 0, last_id = cwd.length();

        while ((start_id < last_id) && (cwd[start_id] == '/')) ++start_id;
        int cur_id = start_id;

        while (start_id < last_id) {
            while ((cur_id < last_id) && (cwd[cur_id] != '/')) ++cur_id;

            if (cur_id != start_id) {
                    st.push_back(string(cwd, start_id, cur_id - start_id));
            }
            start_id = ++cur_id;
            while ((start_id < last_id) && (cwd[start_id] == '/')) ++start_id;
        }
        */
        return st;
    }

    inline int skip_slash(const string& str, int index){
        for (; index < str.length() && str[index] == '/'; ++index){}
        return index;
    }


    string get_token(const string& str, int &index){
        int start_id = index;
        for (; index < str.length() && str[index] != '/'; ++index){};
        return string(str, start_id, index-start_id);
    }
};


int main() {
    string cwd = "/a/b/c";
    string path = "../../../../../../../e";
    //string path = "../d/";
    //string path = "/d";
    cout<<cwd<<"   "<<path<<endl;

    WorkingDirectory workingDir(cwd);
    workingDir.applyPath(path);
    cout<< "'" << workingDir.getCwd()<<"'" << endl;
}

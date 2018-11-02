#include <iostream>
#include <string>

using namespace std;


char* my_strstr(const char* s1,const char* s2) {
    if (!s2 || !s1) return nullptr;
    char* ptr = nullptr;
    while (s1 && s2) {
        while ((s1 && s2) && (*s2 == *s1)) {
            if (!ptr) ptr = const_cast<char*>(s1);
            ++s1; ++s2;
        }
        if (!s2) ptr = nullptr;
        else break;

        ++s1;
    }

    return ptr;
}

int main(){
    string s1 = "Hello world!";
    string s2 = "ella";
    char* pch = my_strstr(s1.c_str(),s2.c_str());
    cout<<"Looking for ("<<s2<<") in ("<<s1<<") : ";
    if (pch) cout<<"found\n";
    else cout<<"not found\n";
    cout<<pch<<endl;

}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string s;
        stack<char> stk;
        if (path[0] != '/')
            return "/";
        else
            stk.push(path[0]);
        int dotsCount = 0;

        for (int i = 1; i < path.length(); i++){
            if (path[i] == '/' && stk.empty()) {
                stk.push(path[i]);
            } else if (path[i] == '/' && stk.top() == '/'){
                if (dotsCount == 1){ dotsCount = 0; }
                else if (dotsCount == 2){
                    if (s.empty()){
                        s += stk.top();
                        stk.pop();
                        dotsCount = 0;
                    } else {
                        s.pop_back();
                        while (s[s.length()-1] != '/')
                            s.pop_back();
                        s.pop_back();
                        dotsCount = 0;
                    }
                } else if (dotsCount >= 3){
                    s += stk.top();
                    stk.pop();
                    for (int j = 1; j <= dotsCount; j++)
                        s += '.';
                    stk.push(path[i]);
                    dotsCount = 0;
                }
            } else if (path[i] == '.')
                dotsCount++;
            else {
                if (!stk.empty()){
                    s += stk.top();
                    stk.pop();
                }
                s += path[i];
            }
        }

        if (dotsCount > 0 && !stk.empty()){
            if (dotsCount == 1){ dotsCount = 0; }
            else if (dotsCount == 2){
                if (s.empty()){
                    s += stk.top();
                    stk.pop();
                } else {
                    s.pop_back();
                    while (s[s.length()-1] != '/')
                        s.pop_back();
                    s.pop_back();
                }
            } else if (dotsCount >= 3){
                s += stk.top();
                stk.pop();
                for (int j = 1; j <= dotsCount; j++)
                    s += '.';
            }
        }

        if (s.empty() && !stk.empty())
            s += stk.top();
        return s;
    }
};

int main(){
    Solution sol;

    string path1 = "/home/"; // /home
    string path2 = "/home//foo/"; // /home/foo
    string path3 = "/home/user/Documents/../Pictures"; // /home/user/Pictures
    string path4 = "/../"; // /../
    string path5 = "/.../a/../b/c/../d/./"; // /.../b/d
    string extraPath1 = "/a/./b/../../c/"; // /c
    string extraPath2 = "/a//b////c/d//././/.."; // /a/b/c
    string extraPath3 = "/"; // /

    cout << sol.simplifyPath(path1) << "\n";
    cout << sol.simplifyPath(path2) << "\n";
    cout << sol.simplifyPath(path3) << "\n";
    cout << sol.simplifyPath(path4) << "\n";
    cout << sol.simplifyPath(path5) << "\n";
    cout << sol.simplifyPath(extraPath1) << "\n";
    cout << sol.simplifyPath(extraPath2) << "\n";
    cout << sol.simplifyPath(extraPath3) << "\n";

    return 0;
}

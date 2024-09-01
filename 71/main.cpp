#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string s;
        if (path[0] != '/'){return s;}
        stack<char> stk;
        size_t activationTimes = 0, dots = 0;
        bool activate = false;
        for (int i = path.size()-1; i > -1; i--){
            if (!activate){
                if (path[i] == '.')
                    dots++;
                if (path[i] == '/') {
                    if (!stk.empty()){
                        if (stk.top() != '/')
                            stk.push(path[i]);
                    }
                    switch(dots){
                        case 1:
                            stk.pop();
                            stk.pop();
                            dots = 0;
                            break;
                        case 2:
                            if (i == 0){
                                char ram = stk.top();
                                stk.pop();
                                stk.pop();
                                stk.pop();
                                stk.push(ram);
                            } else {
                                stk.pop();
                                stk.pop();
                                stk.pop();
                            }
                            dots = 0;
                            activate = true;
                            break;
                        default:
                            break;
                    }
                } else {
                    stk.push(path[i]);
                }
            } else {
                if (path[i] == '/') {
                    activate = false;
                    //stk.push(path[i]);
                }
            }
        }

        while(!stk.empty()){
            s += stk.top();
            stk.pop();
        }

        return s;
    }
};

int main(){
    Solution sol;

    //string path = ".";

    //cout << sol.simplifyPath(path);

    //string path1 = "/home/"; // /home
    //string path2 = "/home//foo/"; // /home/foo
    //string path3 = "/home/user/Documents/../Pictures"; // /home/user/Pictures
    //string path4 = "/../"; // /../
    //string path5 = "/.../a/../b/c/../d/./"; // /.../b/d
    string extraPath1 = "/a/./b/../../c/"; // /c ///TODO
    //string extraPath2 = "/a//b////c/d//././/.."; // /a/b/c ///TODO
    //string extraPath3 = "/"; // / ///TODO
//
    //cout << sol.simplifyPath(path1) << "\n";
    //cout << sol.simplifyPath(path2) << "\n";
    //cout << sol.simplifyPath(path3) << "\n";
    //cout << sol.simplifyPath(path4) << "\n";
    //cout << sol.simplifyPath(path5) << "\n";
    cout << sol.simplifyPath(extraPath1) << "\n";
    //cout << sol.simplifyPath(extraPath2) << "\n";
    //cout << sol.simplifyPath(extraPath3) << "\n";

    return 0;
}

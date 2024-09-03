//
//  Created by acerog on 18/08/24.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string cd = "CD", ud = "UD", p, dotsList;
        string resultPath;
        stack<string> stk;
        size_t dots = 0;

        if(path[0] != '/')
            return "Invalid Path";

        for(size_t i = 1; i <= path.size(); i++){
            if (path[i] == '/' || i == path.size()){
                if(dots != 0){
                    if (dots == 1){
                        if (path[i-2] != '/'){
                            p += dotsList;
                            dotsList.clear();
                        } else {
                            p = cd;
                            dotsList.clear();
                        }
                    } else if (dots == 2){
                        if (path[i-3] != '/'){
                            p += dotsList;
                            dotsList.clear();
                        } else {
                            p = ud;
                            dotsList.clear();
                        }
                    } else {
                        p += dotsList;
                        dotsList.clear();
                    }
                    dots = 0;
                }
                if (!p.empty()){
                    stk.push(p);
                    p.clear();
                }
            } else if (path[i] == '.'){
                dots++;
                dotsList += ".";
            } else {
                p += dotsList + path[i];
                dots = 0;
                dotsList.clear();
            }
        }

        if (stk.empty())
            return "/";

        size_t udCounter = 0;
        while(!stk.empty()){
            if (stk.top() == "CD"){
                stk.pop();
            } else if (stk.top() == "UD"){
                udCounter++;
                stk.pop();
            } else {
                if(udCounter == 0){
                    resultPath = "/" + stk.top() + resultPath;
                    stk.pop();
                } else {
                    stk.pop();
                    udCounter--;
                }
            }
        }

        if( resultPath.empty())
            return "/";

        return resultPath;
    }
};

int main(){
    Solution sol;

    string path1 = "/home/"; // /home
    string path2 = "/home//foo/"; // /home/foo
    string path3 = "/home/user/Documents/../Pictures"; // /home/user/Pictures
    string path4 = "/../"; // /
    string path5 = "/.../a/../b/c/../d/./"; // /.../b/d
    string extraPath1 = "/a/./b/../../c/"; // /c
    string extraPath2 = "/a//b////c/d//././/.."; // /a/b/c
    string extraPath3 = "/"; // /
    string extraPath4 = "/..hidden"; // /..hidden
    string extraPath5 = "/hello../world"; // /hello../world

    cout << sol.simplifyPath(path1) << "\n";
    cout << sol.simplifyPath(path2) << "\n";
    cout << sol.simplifyPath(path3) << "\n";
    cout << sol.simplifyPath(path4) << "\n";
    cout << sol.simplifyPath(path5) << "\n";
    cout << sol.simplifyPath(extraPath1) << "\n";
    cout << sol.simplifyPath(extraPath2) << "\n";
    cout << sol.simplifyPath(extraPath3) << "\n";
    cout << sol.simplifyPath(extraPath4) << "\n";
    cout << sol.simplifyPath(extraPath5) << "\n";


    return 0;
}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string cd = "CD", ud = "UD", p;
        string resultPath;
        stack<string> stk;
        size_t dots = 0;

        if(path[0] != '/') // Si no encuentra el / al inicio, descartamos el path
            return "Invalid Path";

        for(size_t i = 1; i <= path.size(); i++){ // Tokenisamos el Path (de adelante a tras para leer mejor los tokens)
//            switch(path[i]){
//                case ('/'):
//                    if(dots != 0){
//                        if (dots == 1){
//                            p = cd;
//                        } else if (dots == 2){
//                            p = ud;
//                        } else {
//                            while (dots != 0){
//                                p += '.';
//                                dots--;
//                            }
//                        }
//                        dots = 0;
//                    }
//                    if (!p.empty()){
//                        stk.push(p);
//                        p.clear();
//                    }
//                    break;
//                case '.': dots++; break;
//                default:
//                    p = p + path[i];
//                    break;
//            }
            if (path[i] == '/' || i == path.size()){
                if(dots != 0){
                    if (dots == 1){
                        p = cd;
                    } else if (dots == 2){
                        p = ud;
                    } else {
                        while (dots != 0){
                            p += '.';
                            dots--;
                        }
                    }
                    dots = 0;
                }
                if (!p.empty()){
                    stk.push(p);
                    p.clear();
                }
            } else if (path[i] == '.'){
                dots++;
            } else {
                p = p + path[i];
            }
        }

        if (stk.empty()) // Si no entuentro elementos en el stack, muestro la ruta raiz.
            return "/";

        size_t udCounter = 0;
        while(!stk.empty()){ // Lee los Tokens y opera con ellos
            if (stk.top() == "CD"){ // CD -> Solo lo saca del stack
                stk.pop();
            } else if (stk.top() == "UD"){ // UD -> Aumenta el contador de UP y lo saca del stack
                udCounter++;
                stk.pop();
            } else { // Asumimos que lo demas son Nombres de Directorios
                switch(udCounter){
                    case 0: // Si el contador de UP esta en 0, agregamos el token al path
                        resultPath = "/" + stk.top() + resultPath;
                        stk.pop();
                        break;
                    default: // Si el contador de UP esta en cualquier numero que no sea 0, eliminamos un directorio y disminuimos en uno el contador de UP
                        stk.pop();
                        udCounter--;
                        break;
                }
            }
            //resultPath = "/" + stk.top() + resultPath;
            //stk.pop();
        }

        return resultPath;
    }
};

int main(){
    Solution sol;

    //string path = ".";

    //cout << sol.simplifyPath(path);

    //string path1 = "/home/......../no"; // /home
    //string path2 = "/home//foo/"; // /home/foo
    //string path3 = "/home/user/Documents/../Pictures"; // /home/user/Pictures
    //string path4 = "/../"; // /../
    //string path5 = "/.../a/../b/c/../d/./"; // /.../b/d
    string extraPath1 = "/a/./b/../../c/"; // /c
    string extraPath2 = "/a//b////c/d//././/.."; // /a/b/c
    string extraPath3 = "/"; // /
//
    //cout << sol.simplifyPath(path1) << "\n";
    //cout << sol.simplifyPath(path2) << "\n";
    //cout << sol.simplifyPath(path3) << "\n";
    //cout << sol.simplifyPath(path4) << "\n";
    //cout << sol.simplifyPath(path5) << "\n";
    cout << sol.simplifyPath(extraPath1) << "\n";
    cout << sol.simplifyPath(extraPath2) << "\n";
    cout << sol.simplifyPath(extraPath3) << "\n";

    return 0;
}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.push(s[0]);
        for (size_t i = 1; i < s.length(); i++){
            if (!stk.empty() && stk.top() == '(' && s[i] == ')')
                stk.pop();
            else if (!stk.empty() && stk.top() == '[' && s[i] == ']')
                stk.pop();
            else if (!stk.empty() && stk.top() == '{' && s[i] == '}')
                stk.pop();
            else
                stk.push(s[i]);
        }

        if (stk.empty())
            return true;
        else
            return false;
    }
};

int main (){
    string s = "()[]{}";
    Solution solucion;

    cout << solucion.isValid(s);

    return 0;
}

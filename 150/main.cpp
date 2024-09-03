//
// Created by acerog on 2/09/24.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int> stk;
        stk.push(stoi(tokens[0]));
        int i = 1;

        if (tokens.size() == 1){
            return stoi(tokens[0]);
        }

        while (!stk.empty()){
            if (tokens[i] == "+"){
                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1+n2);
                i++;
            } else if (tokens[i] == "-") {
                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1-n2);
                i++;
            } else if (tokens[i] == "*") {
                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1*n2);
                i++;
            } else if (tokens[i] == "/") {
                int n2 = stk.top();
                stk.pop();
                int n1 = stk.top();
                stk.pop();
                stk.push(n1/n2);
                i++;
            } else {
                stk.push(stoi(tokens[i]));
                i++;
            }

            if (i == tokens.size()){
                result = stk.top();
                stk.pop();
            }
        }

        return result;
    }
};

int main() {

    Solution solucion;

    vector<string> tokens_test1 = {"2","1","+","3","*"};
    vector<string> tokens_test2 = {"4","13","5","/","+"};
    vector<string> tokens_test3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    vector<string> tokens_extraTest1 = {"18"};

    cout << solucion.evalRPN(tokens_test1) << "\n";
    cout << solucion.evalRPN(tokens_test2) << "\n";
    cout << solucion.evalRPN(tokens_test3) << "\n";
    cout << solucion.evalRPN(tokens_extraTest1) << "\n";

    return 0;
}

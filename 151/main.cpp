#include <iostream>
#include <string>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string reverse;
        stack<string> tokens;
        tokenization(std::move(s), tokens);

        while(!tokens.empty()){
            if (tokens.size() == 1){ reverse += tokens.top(); }
            else { reverse += tokens.top() + " "; }
            tokens.pop();
        }

        return reverse;
    }
    static void tokenization(const string s, stack<string>& tokens){
        string token;
        for (char i : s){
            if (i != ' '){
                token += i;
            } else {
                if (!token.empty()){
                    tokens.push(token);
                    token.clear();
                }
            }
        }
    }
};

int main() {

    Solution sol;

    cout << sol.reverseWords("the sky is blue") << "\n";
    cout << sol.reverseWords("  hello world  ") << "\n";
    cout << sol.reverseWords("a good   example") << "\n";

    return 0;
}

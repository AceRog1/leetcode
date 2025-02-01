//
// Created by acerog on 01/02/25.
//

#include <iostream>
#include <string>

using namespace std;

/**
 * Beats 100.00% in Runtime (0ms)
 * Beats 74.05% in Memory (9.60mb)
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int alpha[26] = {};
        for (size_t i = 0; i < s.size(); i++){
            int indexI = int(s[i])-97;
            alpha[indexI] = alpha[indexI]+1;
            int indexT = int(t[i])-97;
            alpha[indexT] = alpha[indexT]-1;
        }
        for (int i : alpha)
            if (i != 0) return false;
        return true;
    }
};

int main() {

    Solution s;

    // test 1
    cout << s.isAnagram("anagram", "nagaram") << "\n";

    // test 2
    cout << s.isAnagram("rat", "car") << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        vector<int>::iterator iter;
        for(iter = nums.begin(); iter != nums.end(); iter++) {
            if (hashSet.find(*iter) == hashSet.end())
                hashSet.insert(*iter);
            else return true;
        }
        return false;
    }
};

int main() {

    Solution sol;

    // test 1
    vector<int> v1 = {1,2,3,1};
    cout << sol.containsDuplicate(v1) << "\n"; // 1

    // test 2
    vector<int> v2 = {1,2,3,4};
    cout << sol.containsDuplicate(v2) << "\n"; // 0

    // test 3
    vector<int> v3 = {1,1,1,3,3,4,3,2,4,2};
    cout << sol.containsDuplicate(v3) << "\n"; // 1

    return 0;
}
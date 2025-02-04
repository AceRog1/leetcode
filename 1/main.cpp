//
// Created by acerog on 03/02/25.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Beats 82.86% in Runtime (1ms)
 * Beats 47.89% in Memory (14.74mb)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            auto got = hashMap.find(target-nums[i]);
            if (got == hashMap.end()) hashMap[nums[i]] = i;
            else return {got->second, i};
        }
        return {};
    }
};

int main() {

    Solution sol;

    // test 1
    vector<int> v1 = {2,7,11,15};
    vector<int> rv1 = sol.twoSum(v1, 9);
    cout << "[" << rv1[0] << ", " << rv1[1] << "]\n";

    // test 2
    vector<int> v2 = {3,2,4};
    vector<int> rv2 = sol.twoSum(v2, 6);
    cout << "[" << rv2[0] << ", " << rv2[1] << "]\n";

    // test 3
    vector<int> v3 = {3,3};
    vector<int> rv3 = sol.twoSum(v3, 6);
    cout << "[" << rv3[0] << ", " << rv3[1] << "]\n";

    return 0;
}

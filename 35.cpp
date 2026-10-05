#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;   // next position for a non-zero value
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != pos) {
                    swap(nums[i], nums[pos]);   // skip self-swaps
                }
                ++pos;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    sol.moveZeroes(nums);

    for (int i = 0; i < n; ++i) {
        cout << nums[i] << (i + 1 < n ? " " : "\n");
    }
    return 0;
}
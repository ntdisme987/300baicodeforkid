#include <iostream>
#include <vector>
#include <utility> // For std::swap

using namespace std;

class Solution {
public:
    // Cyclic Sort approach to find the missing number
    int missingNumberCyclicSort(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // STEP 1: Place each number at its correct index (Cyclic Sort)
        // Value x should be located at index x (nums[x] == x)
        while (i < n) {
            int correctIndex = nums[i];

            // If value is within [0, n - 1] and not in its correct position -> swap
            if (nums[i] < n && nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        // STEP 2: Scan the array to find the first mismatched index
        for (int index = 0; index < n; index++) {
            if (nums[index] != index) {
                return index; // Missing number is this index
            }
        }

        // STEP 3: If all positions from 0 to n-1 match, missing number is n
        return n;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter the number of elements n: ";
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    cout << "Enter " << n << " integers in the range [0, " << n << "]:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int missing = sol.missingNumberCyclicSort(nums);

    cout << "\nMissing number: " << missing << "\n";

    return 0;
}
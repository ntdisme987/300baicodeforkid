#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);   // clear the lowest set bit
            ++count;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.hammingWeight(n) << endl;
    return 0;
}
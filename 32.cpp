#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (size_t i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (size_t j = 1; j < strs.size(); ++j) {
                // stop if the string is too short or the character differs
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i) {
        getline(cin >> ws, strs[i]);   // handles empty strings poorly with cin >>, so use getline
    }

    Solution sol;
    cout << "\"" << sol.longestCommonPrefix(strs) << "\"" << endl;
    return 0;
}
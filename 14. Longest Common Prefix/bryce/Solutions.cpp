// Speed: 100%
// Memory: 28.25%

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string& s1, string& s2) { return s1.length() < s2.length(); });

        string str = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].length(); j++) {
                if (str[j] != strs[i][j]) {
                    str = str.substr(0, j);
                    break;
                }
            }
        }

        return str;
    }
};
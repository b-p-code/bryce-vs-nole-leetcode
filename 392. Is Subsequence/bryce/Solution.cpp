class Solution {
public:
    bool isSubsequence(string s, string t) {
		// Extremely fast
		// Speed: 100%
		// Memory: 87.66%
		
		// My thought process is not to find elements to delete,
		// but instead to see if the string contains the proper elements
        int j = 0;
        if (s.length() == 0 && t.length() == 0) {
            return true;
        }
        for (int i = 0; i < t.length(); i++) {

            if (t[i] == s[j]) {
                j++;
            }

            if (j >= s.length()) {
                return true;
            }
        }

        return false;
    }
};
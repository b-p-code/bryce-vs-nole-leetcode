class Solution {
public:
    // Statistics are not good
    // Speed: 32.6%
    // Memory: 8.13%
    // Apologies Nole, I picked a compiler-specific type of problem

    int countValidWords(string s) {
        // Necessary inclusion of a space delimiter so no EOF is needed
        s += " ";

        // Best way to handle this is with an FSA table IMO
        // Col 1: lowercase letters
        // Col 2: hyphens
        // Col 3: punctuation
        // Col 4: spaces
        // Col 5: anything else
        // Row 1: initial state
        // Row 2: Word containing only letters or digits (no hyphens yet)
        // Row 3: Word containing hypen (but none to the left)
        // Row 4: Word containing hyphen (but at least one character on the right)
        // Row 5: Word ending in puncuation mark
        // The FSA table will return 1000 if a valid token exists
        // It will return -1 otherwise
        int table[5][5] = {
            {    1,   -1,    4,    0,   -1},
            {    1,    2,    4, 1000,   -1},
            {    3,   -1,   -1,   -1,   -1},
            {    3,   -1,    4, 1000,   -1},
            {   -1,   -1,   -1, 1000,   -1}
        };

        int count = 0;
        int state = 0;
        string temp;
        for (int i = 0; i < s.size(); i++) {
            int nextState = table[state][map(s[i])];
            cout << nextState << " " << endl;
            temp += s[i];
            if (nextState > 999) {
                count++;
                cout << temp << " ";
                nextState = 0;
                temp = "";
            }
            if (nextState == -1) {
                while (!isspace(s[i]) && i < s.size()) {
                    i++;
                }
                nextState = 0;
                temp = "";
            }

            state = nextState;
        }

        return count;
    }

    int map(char c) {
        if (isalpha(c)) {
            return 0;
        } else if (c == '-') {
            return 1;
        } else if (c == ',' || (c == '!') || (c == '.')) {
            return 2;
        } else if (c == ' '){
            return 3;
        } else {
            return 4;
        }
    }
};

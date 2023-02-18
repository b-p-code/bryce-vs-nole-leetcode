// Speed: 100%
// Memory: 65.37%
class Solution {
public:
    // Col 1: G
    // Col 2: (
    // Col 3: )
    // Col 4: a
    // Col 5: l
    // Col 6: anything else
    int fsa[4][6] = {
        { 1000,    1,    -1,    -1,    -1,    -1},
        {   -1,   -1,  1001,     2,    -1,    -1},
        {   -1,   -1,    -1,    -1,     3,    -1},
        {   -1,   -1,  1002,    -1,    -1,    -1}
    };
    string interpret(string command) {
        string output = "";
        int currentState = 0;
        for (int i = 0; i < command.size(); i++) {
            int nextState = fsa[currentState][map(command[i])];
            if (nextState > 999) {
                if (nextState == 1000) {
                    output += "G";
                }
                if (nextState == 1001) {
                    output += "o";
                }
                if (nextState == 1002) {
                    output += "al";
                }
                nextState = 0;
            }

            currentState = nextState;
        }

        return output;
    }

    int map(char c) {
        switch (c) {
            case 'G':
                return 0;
            case '(':
                return 1;
            case ')':
                return 2;
            case 'a':
                return 3;
            case 'l':
                return 4;
            default:
                return 5;
        }
    }
};
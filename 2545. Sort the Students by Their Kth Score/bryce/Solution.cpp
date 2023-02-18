// Speed: 98.73%
// Memory: 39.47%
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<int> kthrow;

        for (int i = 0; i < score.size(); i++) {
            kthrow.push_back(score[i][k]);
        }

        sort(kthrow.begin(), kthrow.end(), greater<int>());

        vector<vector<int>> sorted;

        for (int i = 0; i < kthrow.size(); i++) {
            for (int j = 0; j < score.size(); j++) {
                if (kthrow[i] == score[j][k]) {
                    sorted.push_back(score[j]);
                }
            }
        }

        return sorted;
    }
};
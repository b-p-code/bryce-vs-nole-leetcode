class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // Speed: 80.3%
        // Memory: 19.97%
        vector<int> x_values;
        for (vector<int> pairs : points) {
            x_values.push_back(pairs[0]);
        }

        sort(x_values.begin(), x_values.end());

        int max = -1;

        for (int i = 0; i < x_values.size() - 1; i++) {
            int dist = x_values[i + 1] - x_values[i];
            if (dist > max) {
                max = dist;
            }
        }

        return max;
    }
};
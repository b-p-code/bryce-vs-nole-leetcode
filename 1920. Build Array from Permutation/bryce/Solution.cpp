class Solution {
public:
    vector<int> buildArray(vector<int>& n) {
		// Fairly fast
		// Speed: beats 53.23%
		// Memory: beats 81.10%
        // Simple solution
        vector<int> nums = n;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = n[n[i]];
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
		// Extremely fast
		// Speed: 96.98%
		// Memory: 39.98%
		// Simple solution
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};
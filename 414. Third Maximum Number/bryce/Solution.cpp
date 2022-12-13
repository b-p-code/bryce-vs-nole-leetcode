class Solution {
public:
    int thirdMax(vector<int>& nums) {
	// Actually quite fast
	// Speed: 66.78%
	// Memory: 89.30%
        // Going for clean code
        // This sorts and then erases unique values
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        // Return the third back or the max
        if (nums.size() > 2) {
            return nums[nums.size() - 3];
        } else {
            return nums[nums.size() - 1]; 
        }
    }
};

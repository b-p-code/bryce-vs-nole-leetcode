// Had some trouble with this one, had to look at solutions to find the 'trick'
// but this is my own implementation of said trick

// Speed: 79.42%
// Memory: 16.37%

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int middle;

        if (nums.size() == 1) {
            return nums[0];
        }

        while (l < r) {
            middle = (l + r) / 2;

            int comp;
            if (middle % 2 == 0) {
                comp = middle + 1;
                if (nums[comp] == nums[middle]) {
                    l = middle + 1;
                } else {
                    r = middle;
                }
            } else {
                comp = middle - 1;
                if (nums[comp] == nums[middle]) {
                    l = middle + 1;
                } else {
                    r = middle;
                }
            }
        }
        return nums[r];
    }
};
// Speed: 47.17% (to-do: make this iterative, will be faster)
// Memory: 77.52% (because using references in parameters)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int lower, int upper) {
        int middle = upper + (lower - 1) / 2;

        if (upper >= lower) {
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < target) {
                return binarySearch(nums, target, middle + 1, upper);
            } else if (nums[middle] > target) {
                return binarySearch(nums, target, lower, middle - 1);
            }
        } else {   
            return lower;
        }

        return -1;
    }
};
/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]}
 */
var pivotArray = function(nums, pivot) {
    // Speed: 85.71%
    // Memory: 31.34%

    let index = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === pivot) {
            index = i;
        }
    }

    let left = [];
    let middle = [];
    let right = [];
    middle.push(nums[index]);

    for (let i = 0; i < nums.length; i++) {
        if (i !== index) {
            if (nums[i] < nums[index]) {
                left.push(nums[i]);
            } else if (nums[i] === nums[index]) {
                middle.push(nums[i]);
            } else {
                right.push(nums[i]);
            }
        }
    }

    return [].concat(left, middle, right);
};
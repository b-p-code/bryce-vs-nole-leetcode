int differenceOfSum(int* nums, int numsSize){
    // Speed: 96.36%
    // Memory: 94.55%

    long int elementSum = 0;
    long int digitSum = 0;

    int i;
    
    for (i = 0; i < numsSize; i++) {
        elementSum += nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        nums[i];
        while (nums[i] != 0) {
            digitSum += nums[i] % 10;
            nums[i] /= 10;
        }
    }

    return abs(elementSum - digitSum);
}
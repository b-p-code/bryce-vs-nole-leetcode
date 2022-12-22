// Brute force solution that is actually decently fast all things considered
// Speed: 46.81%
// Memory: 25.53%

bool isStrictlyIncreasing(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] >= nums[i]) {
            return false;
        }
    }

    return true;
}

int* removeOneElement(int* nums, int index, int numsSize) {
    int* newArr = malloc ((numsSize - 1) * sizeof(int));
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i != index) {
            newArr[j] = nums[i];
            j++;
        }
    }

    return newArr;
}

bool canBeIncreasing(int* nums, int numsSize){
    if (isStrictlyIncreasing(nums, numsSize)) {
        return true;
    } else {
        for (int i = 0; i < numsSize; i++) {
            int* arrWithElementRemoved = removeOneElement(nums, i, numsSize);
            if (isStrictlyIncreasing(arrWithElementRemoved, numsSize - 1)) {
                free(arrWithElementRemoved);
                return true;
            }
            free(arrWithElementRemoved);
        }
    }

    return false;
}
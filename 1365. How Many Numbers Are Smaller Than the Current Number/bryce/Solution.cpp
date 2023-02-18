// Speed: 74.10%
// Memory: 6.62%
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        map<int, int> mp;

        for (int i = 0; i < temp.size(); i++){
            mp.insert(pair<int, int>(temp[i], i));
        }

        for (int i = 0; i < nums.size(); i++) {
            temp[i] = (mp.find(nums[i]))->second;
        }

        return temp;
    }
};
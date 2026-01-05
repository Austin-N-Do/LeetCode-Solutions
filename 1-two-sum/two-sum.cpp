class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for (int i = 0; i < nums.size(); i++) {
            int remainder = target - nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                if (remainder == nums[j]) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
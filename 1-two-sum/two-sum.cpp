class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if complement exists in map
            if (map.find(complement) != map.end()) {
                // Found it! Return both indices
                return {map[complement], i};
            }

            // Didn't find it, so add current number to map
            map[nums[i]] = i;
        }
        return {};
    }
};
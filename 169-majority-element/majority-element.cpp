class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        
        // Step 1: Count all elements
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;  // Increment count for this number
        }
        
        // Step 2: Find the element with highest count
        int majorityElement = 0;
        int maxCount = 0;
        
        for (auto& pair : count) {
            if (pair.second > maxCount) {
                maxCount = pair.second;           // What should this be?
                majorityElement = pair.first;     // What should this be?
            }
        }
        
        return majorityElement;
    }
};
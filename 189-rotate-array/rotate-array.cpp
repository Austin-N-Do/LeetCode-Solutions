class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int nums2[nums.size()];

        for (int i = 0; i < nums.size(); i++) {
            int new_index = (i + k) % nums.size();
            nums2[new_index] = nums[i];
        }
          for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums2[i];
        }
    }
};
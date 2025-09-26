class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // check edge case
        if (nums.empty()) return 0;

        // write pointer
        int i = 0; 

        // iterates through the array
        for (int j = 1; j < nums.size(); j++) { 
            // checks if the starting value is the same as the next one
            if (nums[i] != nums[j]){

                // if the number isnt the same, move forward in the array
                i++;
                // set the next number as the new one to compare
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }
};
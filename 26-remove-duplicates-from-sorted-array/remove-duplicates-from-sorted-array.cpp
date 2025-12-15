class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]!=nums[k-1]){ //in order to get the first element and check the previous number store to see if the numbers are duplicates
            nums[k]= nums[i];
            k++;
            }
        }
        return k;
    }
};
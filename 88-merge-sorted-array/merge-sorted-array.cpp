class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;         // last valid index in nums1
    int j = n - 1;         // last index in nums2
    int k = m + n - 1;     // last slot in nums1

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];  // place nums1's value
            i--;                   // move nums1 pointer
        }   else {
            nums1[k] = nums2[j];  // place nums2's value
            j--;                   // move nums2 pointer
        }
        k--;                       // move to next slot backwards
    }
    }
};
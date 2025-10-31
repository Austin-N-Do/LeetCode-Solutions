#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   // store indices
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain decreasing order — remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // Push current index
            dq.push_back(i);

            // If window has reached size k, record the max (at dq.front)
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

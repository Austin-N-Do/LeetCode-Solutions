#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        // Add a sentinel (0) at the end to ensure stack empties
        heights.push_back(0);

        for (int i = 0; i < heights.size(); ++i) {
            // While current bar is lower than top of stack → calculate area
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                // Width = distance between current index and stack top after pop
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
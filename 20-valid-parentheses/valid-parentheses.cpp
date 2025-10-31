#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // If it's an opening bracket, push it
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket, check for matching
            else {
                if (st.empty()) return false; // nothing to match with

                char top = st.top();
                st.pop();

                // Check if types match
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty, all opened were closed properly
        return st.empty();
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix;
        for (int i = 0; i < strs[0].length(); i++) {              // for each position
            char reference = strs[0][i];            // reference character
    
            for (int j = 1; j < strs.size(); j++) { // check all other strings
                if (i >= strs[j].length()) {
                return commonPrefix;
                }
            
                if (strs[j][i] != reference) {
                return commonPrefix;
                }
            }        
            commonPrefix += strs[0][i];  
        }
        return commonPrefix;
    }
};
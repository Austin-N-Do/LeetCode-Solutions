class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.length() > haystack.length() || needle.empty()){
            return -1;
        }
        /* 
        check loop runs as long as the haystack size is larger than needle, 
        since otherwise, the needle wont fit any there is not any point in continuing.
        */

        /*for loop explanation
as long as j is smaller than needle
what this does is it checks i + j in the sense that it compares the letters of the needle, 
the for loop checks if it is equal to the hay stack and if the check fails, 
If any character does not match, 
stop checking this starting index i then move to the next possible starting index in haystack

haystack = "sadbutsad"
needle = "sad"
i = 0 → we start checking from haystack[0]
j = 0 → compare haystack[0 + 0] = haystack[0] = 's' with needle[0] = 's' 
j = 1 → compare haystack[0 + 1] = haystack[1] = 'a' with needle[1] = 'a' 
j = 2 → compare haystack[0 + 2] = haystack[2] = 'd' with needle[2] = 'd' 
Since all characters match, we know needle occurs starting at i = 0.
*/
        for (int i = 0; i <= haystack.size() - needle.size(); i++){
            bool match = true;
            for (int j = 0; j < needle.size(); j++){
                if (haystack[i + j] != needle[j]){
                    match = false;
                }
            }
            if (match) return i;
        }

        return -1;
    }
};


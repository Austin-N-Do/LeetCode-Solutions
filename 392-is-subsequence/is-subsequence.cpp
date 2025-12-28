class Solution {
public:
    bool isSubsequence(string s, string t) {
        int key = 0;
        if (s.length() == 0){
            return true;
        }
        for (int i = 0; i < t.length(); i++){
            if (s[key] == t[i]){
                key++;
                if (key == s.length()){
                return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCount;
        for (int i = 0; i < magazine.length(); i++){
            charCount[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.length(); i++){
           if (charCount[ransomNote[i]] > 0) {
                charCount[ransomNote[i]]--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
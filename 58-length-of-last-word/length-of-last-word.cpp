class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
bool countingWord = false;

for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] != ' ') {
        countingWord = true;
        count++;
    } else if (countingWord) {
        // We were counting a word, but now hit a space - we're done!
        break;
    }
    // else: still in trailing spaces, keep going
}

return count;
    }
};
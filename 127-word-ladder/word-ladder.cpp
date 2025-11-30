#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord not in list, no solution
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        // BFS
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                
                // If we reached the end word
                if (word == endWord) {
                    return level;
                }
                
                // Try changing each character
                for (int j = 0; j < word.length(); j++) {
                    char originalChar = word[j];
                    
                    // Try all 26 letters
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        
                        word[j] = c;
                        
                        // If this word is in the dictionary
                        if (wordSet.find(word) != wordSet.end()) {
                            q.push(word);
                            wordSet.erase(word);  // Mark as visited
                        }
                    }
                    
                    word[j] = originalChar;  // Restore
                }
            }
            
            level++;
        }
        
        return 0;  // No path found
    }
};
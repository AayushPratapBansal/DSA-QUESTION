class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
           int charCount[26] = {0};

    // Count each character in magazine
    for (char c : magazine) {
        charCount[c - 'a']++;
    }

    // Check each character in ransomNote
    for (char c : ransomNote) {
        charCount[c - 'a']--;
        // If count goes below zero, magazine does not have enough of this character
        if (charCount[c - 'a'] < 0) {
            return false;
        }
    }
    
    return true;
    }
};
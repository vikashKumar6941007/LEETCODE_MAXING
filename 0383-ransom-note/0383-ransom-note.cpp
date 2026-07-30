class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // Store the frequency of characters in magazine
        unordered_map<char, int> mp;

        for (char c : magazine) {
            mp[c]++;
        }

        // Check whether every character of ransomNote exists
        for (int i = 0; i < ransomNote.size(); i++) {

            // Character is unavailable
            if (mp[ransomNote[i]] < 1) {
                return false;
            }

            // Use one occurrence of the character
            mp[ransomNote[i]]--;
        }

        return true;
    }
};
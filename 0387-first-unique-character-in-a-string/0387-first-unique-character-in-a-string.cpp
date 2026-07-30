class Solution {
public:
    int firstUniqChar(string s) {

        // Store the frequency of every character using hashmap
        unordered_map<char, int> mp;

        // Count the occurrences of each character
        for (char c : s) {
            mp[c]++;
        }

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            // If  freq=1 , it is unique
            if (mp[s[i]] == 1) {
                return i;
            }
        }

        // No unique char
        return -1;
    }
};

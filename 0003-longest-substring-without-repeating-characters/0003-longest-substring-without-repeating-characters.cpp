class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Stores frequency of char in the current window
        unordered_map<char, int> mpp;

        // low pointer 
        int low = 0;

        // Max length of a valid substring
        int ans = 0;

        // Expand the window with right high pointer
        for (int high = 0; high < s.size(); high++) {

            // Include the current char
            mpp[s[high]]++;

            // If current char is repeated,
            // shrink the window until it becomes unique again
            while (mpp[s[high]] > 1) {

                // Remove the leftmost charfrom t he window
                mpp[s[low]]--;

                // Move the left pointer forward
                low++;
            }

            // Current window contains all unique char so calculating max length 
            ans = max(ans, high - low + 1);
        }

        return ans;
    }
};
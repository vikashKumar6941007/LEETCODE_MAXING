class Solution {

public:
    int totalFruit(vector<int>& fruits) {

        // Stores the frequency of each fruit type in the current window
        unordered_map<int, int> mp;

        // Left pointer of the sliding window
        int left = 0;

        // Stores the maximum number of fruits collected
        int ans = 0;

        // Expand the window by moving the right pointer
        for (int right = 0; right < fruits.size(); right++) {

            // Include the current fruit in the window
            mp[fruits[right]]++;

            // If more than 2 distinct fruit types are present,
            // shrink the window from the left
            while (mp.size() > 2) {

                // Remove one occurrence of the leftmost fruit
                mp[fruits[left]]--;

                // If its frequency becomes 0,
                // remove it from the map completely
                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);

                // Move the left pointer forward
                left++;
            }

            // At this point the window always contains
            // at most 2 distinct fruit types.

            // Update the maximum valid window size
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
          
};
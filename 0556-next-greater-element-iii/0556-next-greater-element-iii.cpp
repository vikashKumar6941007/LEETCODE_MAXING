class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);

        int i = s.size() - 2;

        // Step 1: Find the pivot
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        // No next greater number exists
        if (i < 0) {
            return -1;
        }

        int j = s.size() - 1;

        // Step 2: Find the next larger element
        while (s[j] <= s[i]) {
            j--;
        }

        // Step 3: Swap the two elements
        swap(s[i], s[j]);

        // Step 4: Reverse the suffix
        reverse(s.begin() + i + 1, s.end());

        long long ans = stoll(s);

        // Check 32-bit integer range
        if (ans > INT_MAX) {
            return -1;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Stores answer for each index
        vector<int> ans(n, -1);

        // Monotonic decreasing stack (stores values)
        stack<int> st;

        // Traverse twice from right to left
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Current index after wrapping around
            int idx = i % n;

            // Remove all smaller or equal elements
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Only fill answers during the first pass
            // (when idx belongs to original array)
            if (i < n) {

                if (!st.empty())
                    ans[idx] = st.top();
                else
                    ans[idx] = -1;
            }

            // Push current element for future comparisons
            st.push(nums[idx]);
        }

        return ans;
    }
};
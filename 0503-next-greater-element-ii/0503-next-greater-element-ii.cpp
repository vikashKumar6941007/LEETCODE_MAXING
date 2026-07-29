class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Stores answer for each index
        vector<int> ans(n, -1);

        // Monotonic decreasing stack (stores values)
        stack<int> st;

        // Traverse twice from right to left to make the array double without actually doubling it
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Current index after wrapping around, we double the value of n for i, so it should not get out of bound from the vector from which we are searching
            int idx = i % n;

            // Remove all smaller or equal elements
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Only fill answers during i < n , bcz i actually we are using this 2*n to fill the stack with the vector's elements and then start our next greater stack algo to really get the answer by modify ans vector
            // (when idx belongs to original vector)
            if (i < n) {

                if (!st.empty())
                    ans[idx] = st.top();
                else
                    ans[idx] = -1;
            }

            // Push current element for future comparisons (filling the stack for later use when original indices arrives)
            st.push(nums[idx]);
        }

        return ans;
    }
};
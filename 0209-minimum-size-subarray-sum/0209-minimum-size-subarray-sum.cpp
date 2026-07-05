class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // intialize needed variables
        int n = nums.size();
        int sum = 0, low = 0, high = 0, len = 0, res = INT_MAX;
        // run till high become out of bound from the array
        while (high < n) {
            // inceases sum to find windows value
            sum += nums[high];
            // shrink window until sum get smaller than target
            while (sum >= target) {
                // length of window on which we get the answer per iteration
                len = high - low + 1;
                // storing smallest length of widnow fromprevious and current size
                res = min(res, len);
                // shrink window
                low++;
                // calculate new sum
                sum = sum - nums[low - 1];
            }
            // when sum is smaller than target increases window size
            high++;
        }
        // return res and if res not updated return zero
        return (res == INT_MAX) ? 0 : res;
    }
};
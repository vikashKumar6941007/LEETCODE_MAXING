class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int best_ending = nums[0];
        int maxsum = nums[0], minsum = nums[0];
        int maxend = nums[0], minend = nums[0];
        int total = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // cal total of all interger
            total += nums[i];
            // finding maximum sum and minimum sum from the vector
            maxsum = max(maxsum + nums[i], nums[i]);
            maxend = max(maxend, maxsum);
            minsum = min(minsum + nums[i], nums[i]);
            minend = min(minend, minsum);
        }
        // all elements are negative hence return only one minimum value element
        // which is maxend
        if (maxend < 0) {
            return maxend;
        }
        // returning maxend(normal kadane's) or total-minend(which is sum of all
        // element minus minimum sum )
        return max(total - minend, maxend);
    }
};
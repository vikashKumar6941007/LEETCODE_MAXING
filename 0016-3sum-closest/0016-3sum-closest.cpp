class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sorted the vector

        sort(nums.begin(), nums.end());
        // introduce min_dif to infinity
        int sum = 0;
        int real_sum;
        int n = nums.size();
        int min_dif = INT_MAX;
        // for loop to fix the 1st pointer

        for (int i = 0; i < n - 2; i++) {
            int first = nums[i];
            // intialize variable for  using two pointer
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                //  sum of all 3 pointers

                sum = first + nums[left] + nums[right];
                // compare absolute of the difference with the minimum
                // difference and updated if new difference minimum difference
                // found
                if (abs(sum - target) < min_dif) {
                    min_dif = abs(sum - target);
                    // updated returning sum
                    real_sum = sum;
                }
                // move pointer as per requirement
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                    // return case of when target==sum
                } else {
                    return sum;
                }
            }
        }
        return real_sum;
    }
};
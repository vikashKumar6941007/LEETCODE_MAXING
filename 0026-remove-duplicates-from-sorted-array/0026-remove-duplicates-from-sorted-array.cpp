class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0, high = 1;
        int n = nums.size();

        if (n == 0)
            return 0;

        while (high < n) {

            if (nums[low] == nums[high]) {
                high++;
            } else {

                low++;
                nums[low] = nums[high];
                high++;
            }
        }
        return low + 1;
    }
};
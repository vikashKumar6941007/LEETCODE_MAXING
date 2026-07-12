class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        // Calculate total sum of vector
        for (int num : nums) {
            total += num;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            //leftSum + rightSum gives total sum of array BUT exclude that index so it give the prefix sum till that index
            int rightSum = total - leftSum - nums[i];
            //condition satisfied
            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
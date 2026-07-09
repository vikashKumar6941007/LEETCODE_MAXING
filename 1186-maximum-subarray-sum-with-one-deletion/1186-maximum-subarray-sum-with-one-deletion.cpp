class Solution {
public:
    int maximumSum(vector<int>& nums) {

        int no_delete = nums[0];
        int one_delete = INT_MIN;
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int prev_no = no_delete;
            int prev_one = one_delete;

            no_delete = max(nums[i], prev_no + nums[i]);

            if(prev_one == INT_MIN)
                one_delete = prev_no;
            else
                one_delete = max(prev_one + nums[i], prev_no);

            ans = max(ans, max(no_delete, one_delete));
        }

        return ans;
    }
};
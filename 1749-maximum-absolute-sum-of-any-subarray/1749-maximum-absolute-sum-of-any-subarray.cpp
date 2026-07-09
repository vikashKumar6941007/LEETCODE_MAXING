class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        //kadane's algo just taking absolute in the end thats it

        int min_sum=nums[0];
        int max_sum=nums[0];
        int ans=abs(nums[0]);

        for(int i=1;i<nums.size();i++){
            
            
            int min_val=min_sum;
            int max_val=max_sum;

            min_sum=min(min_val+nums[i],nums[i]);
            max_sum=max(max_val+nums[i],nums[i]);

            ans=max(ans,max(abs(min_sum),abs(max_sum)));

        }
        return ans;
        
    }
};
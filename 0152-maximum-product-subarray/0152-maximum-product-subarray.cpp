class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int min_ending=nums[0];
        int max_ending=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            
            int prevMin = min_ending;
            int prevMax = max_ending;

            int v1 = prevMin * nums[i];
            int v2 = prevMax * nums[i];
            int v3 = nums[i];

            min_ending=min(v3,min(v1,v2));
            max_ending=max(v3,max(v1,v2));

            ans=max(ans,max_ending);
        }

        return ans;
        
    }
};
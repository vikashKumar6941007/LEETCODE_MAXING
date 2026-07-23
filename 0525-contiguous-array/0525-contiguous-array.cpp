class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero=0;
        int one=0;
        int res=0;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){

            if(nums[i]==0)
            zero++;
            else
            one++;
            // diff btwn the counts of two binary choices
            int diff=zero-one;
            
            if(diff==0){
            res=max(res,i+1);
            continue;
            }
            //diff not found in hashmap
            if(mp.find(diff)==mp.end()){
                mp[diff]=i;
            }
            //when diff is present on hashmap then, calculate the valid subarray size and update max of the two res and len , and don't update index bcz we need maximum subarray length
            else{
                int idx=mp[diff];
                int len=i-idx;
                res=max(res,len);
            }
        }
        return res;
       
    }
};
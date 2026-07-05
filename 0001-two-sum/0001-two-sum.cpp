class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // made a map wuth key, value pair
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            // that number and that number needed what value to get target
            int cur=nums[i];
            int com=target-cur;
            // search remaining number in the hashmap as it search  in O(1) time complexity
            if(mpp.count(com)){
                // return in vector format {the index value which stored in map as a value which related to remaining value , current index of the value}
            return {mpp[com],i};
            }
            // inserting new data in the hashmap in its key, value pair format
          mpp[cur]=i;
        }
        return {} ;
    }

};
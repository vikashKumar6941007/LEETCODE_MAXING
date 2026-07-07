class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //slow fast pointer in array using its indecies

        int n = nums.size();
        if (n == 0 or n == 1) {
            return 0;
        }
        int slow = 0, fast = 0;

        while (true) {
            //sending pointer to next element using value of that index
            slow = nums[slow];

            fast = nums[fast];
            fast = nums[fast];
            //cycle detected because two values point to same index
            if (slow == fast) {
                slow = 0;
                //speed same krdo to find entry point of the cycle
                while (slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
            
        }
        return 0;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // return a vector vector of int type
        vector<vector<int>> res;
        // sort using internal sort function
        sort(nums.begin(), nums.end());

        // select i and run it to  3rd last value

        for (int i = 0; i < nums.size() - 2; i++) {
            // slipping same values of i
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }
            // wrote code for again 2 pointer as a 2 sum problem
            else {
                // marked left and right pointers
                int ans = -1 * nums[i];
                int k = i + 1, j = nums.size() - 1;
                // run when left smaller than right
                while (k < j) {
                    int sum = nums[k] + nums[j];
                    if (sum == ans) {
                        // store that particular vector that satisfy the
                        // condition
                        res.push_back({nums[i], nums[k], nums[j]});
                        k++;
                        j--;
                        // check left and right condition for internal loop
                        while (k < j and nums[k] == nums[k - 1]) {
                            k++;
                        }
                        while (k < j and nums[j] == nums[j + 1]) {
                            j--;
                        }
                    }
                    // handle other cases of sum and ans relation
                    else if (sum < ans) {
                        k++;
                    } else {
                        j--;
                    }
                }
            }
        }
        return res;
    }
};
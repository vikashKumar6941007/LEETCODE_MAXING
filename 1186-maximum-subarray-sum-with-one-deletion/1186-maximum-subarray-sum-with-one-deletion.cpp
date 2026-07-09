class Solution {
public:
    int maximumSum(vector<int>& arr) {

        // Think of it as Kadane with two lives:

        // keep: "I haven't used my deletion yet."
        // drop: "I've already used my one deletion."

        // At each element:

        // keep behaves exactly like Kadane.
        // drop either:
        // extends a subarray where the deletion was already used, or
        // uses the deletion right now by skipping the current element (keep
        // from the previous position).

        int keep = arr[0];
        int drop = 0;

        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {

            int newKeep = max(arr[i], keep + arr[i]);

            int newDrop = max(drop + arr[i], keep);
            //having keep means arr[i] is the dropped one
            keep = newKeep;
            drop = newDrop;

            ans = max(ans, max(keep, drop));
        }

        return ans;
    }
};
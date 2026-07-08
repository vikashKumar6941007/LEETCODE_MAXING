class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
    
        //running loop in reverse and convert to zero if encounters 9 else just increment and return the vector
        for (int i = n - 1; i >= 0; i--) {

            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }
        //if all digits are zero and never get to inner loop then add extra 1 at start and return the vector
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
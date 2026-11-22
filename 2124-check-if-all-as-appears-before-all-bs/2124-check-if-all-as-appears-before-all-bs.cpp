class Solution {
public:
    bool checkString(string s) {
        int size = s.size();

        // Loop up to size - 1 so i + 1 never goes out of bounds
        for (int i = 0; i < size - 1; i++) {
            if (s[i] > s[i + 1]) {
                return false;
            }
        }
        
        return true; // Guaranteed return if no 'b' comes before 'a'
    }
};

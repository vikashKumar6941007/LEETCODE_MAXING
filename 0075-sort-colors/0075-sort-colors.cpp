class Solution {
public:
    void sortColors(vector<int>& arr) {
        // set three pointer = low follow 0 , mid follow 1 , high follow 2
        int low = 0, mid = 0, high = arr.size() - 1;
        // loop till mid crosses the high pointer
        while (mid <= high) {
            // mid always follow 1 so swap it with low pointer as low follows 1
            // and increment both the pointers
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                mid++;
                low++;
                // mid follow 1 perfect condition  just increment mid pointer
            } else if (arr[mid] == 1) {
                mid++;
                // swap it with high pointer as high follows 2 and only
                // decrement high bcz we don't know what came after swapping
                // with high can be any value
            } else if (arr[mid] == 2) {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
class Solution {
public:

    int characterReplacement(string s, int k) {
        //intialized required pointer and values for sliding window

        int low = 0, high = 0, res = INT_MIN,max_int=0;

        int n = s.size();
        //vector of 26 size to store all capital Alphbets
        vector<int> f(26, 0);

        for (high = 0; high < n; high++) {
            //pushed element on the index corresponding to his ASCII value
            f[s[high]-'A']++;

            int len = high - low + 1;
            //find frequency of current index
            int freq=f[s[high]-'A'];
            //finding max occurance of any value
            max_int = max(max_int,freq);
            //taking diff to find how many characters are here for replacement
            int diff = len-max_int;
            //if replacing character higher than replacement chances given to us then
            //decrease the window size until we false the while loop situation
            while (diff > k) {

                f[s[low]-'A']--;
                low++;    
                len=high-low+1;
                diff = len - max_int;
            }
            //get max of both the value and return in the end
            res = max(res, len);
        }
        return res;
    }
};
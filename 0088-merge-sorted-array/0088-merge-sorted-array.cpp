class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if 2nd vector is empty no need to return as Q said just nums1 should be updated
        if(nums2.size()==0){}
        // when nums2 is not empty
        //copy the data of nums1 till we have valid numbers after that empty it then marge the copy vector and empty vector into nums 1 vector
        else{
        vector<int> copy(nums1.begin(), nums1.begin() + m);
        nums1.clear();
        int i=0,j=0;
        while(i<copy.size() and j<nums2.size()){
                if(copy[i]<=nums2[j]){
                    nums1.push_back(copy[i]);
                    i++;
                }
                else{
                    nums1.push_back(nums2[j]);
                    j++;
            }
            }

              // if vectors are not of same length then use this to add remaining elements
            while(i<copy.size()){
                nums1.push_back(copy[i]);
                i++;
            }

            while(j<nums2.size()){
                nums1.push_back(nums2[j]);
                j++;

            }
        
            }
    }
};
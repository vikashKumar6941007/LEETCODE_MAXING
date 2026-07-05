class Solution {
public:
// square a vector elements
    void square_array(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
    }
    vector<int> sortedSquares(vector<int>& nums) {
        // classify positive and negative element 
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<nums.size();i++){
            if (nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        // done what is return below
        reverse(neg.begin(), neg.end());
        square_array(pos);
        square_array(neg);
        nums.clear();
        // check of empty array condition and return on that bases
        if(neg.size()==0){
            return pos;
        }
        else if(pos.size()==0){
            return neg;
        }
        //merging them back to nums vector by checking which element is small
        else{
            int i=0,j=0;
            while(i<neg.size() and j<pos.size()){
                if(neg[i]<=pos[j]){
                    nums.push_back(neg[i]);
                    i++;
                }
                else{
                    nums.push_back(pos[j]);
                    j++;
            }
            // if vectors are not of same length then use this to add remaining elements
            }
            while(i<neg.size()){
                nums.push_back(neg[i]);
                i++;

            }
            while(j<pos.size()){
                nums.push_back(pos[j]);
                j++;

            }
            return nums;

        }


    }
};
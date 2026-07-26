class Solution {
public:
  
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>> ans;
        //2 pointer i and j to keep track of both list bcz they are not sorted combinely        
        int i=0,j=0;

        while (i < firstList.size() && j < secondList.size()) {
            //max value of that elements 1st value
            int start = max(firstList[i][0], secondList[j][0]);
            //min value of that elements 2nd value
            int end   = min(firstList[i][1], secondList[j][1]);

            // If they overlap
            if (start <= end) {
                ans.push_back({start, end});
            }

            // Move the interval that ends first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;

    }
       
};
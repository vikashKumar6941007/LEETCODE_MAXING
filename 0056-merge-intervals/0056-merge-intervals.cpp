class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {

        //sorting the arr according to start point
        sort(arr.begin(),arr.end());

        //response vector of vector
        vector<vector<int>> res;

        int start1=arr[0][0];
        int end1=arr[0][1];

        for(int i=1;i<arr.size();i++){
            int start2=arr[i][0];
            int end2=arr[i][1];
            //condition for merging intervals
            if(end1>=start2){
                start1=start1;
                end1=max(end1,end2);
                continue;
            }
            //not merged
            else{
                res.push_back({start1,end1});
                start1=start2;
                end1=end2;

            }

        }
        //pushing final vector interval
        res.push_back({start1,end1});

        return res;
        
        
    }
};
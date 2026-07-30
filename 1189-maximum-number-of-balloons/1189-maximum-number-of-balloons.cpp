class Solution {
public:
    int maxNumberOfBalloons(string text) {

        string s="balloon";
        int res=INT_MAX;
        //map for storing all character
        unordered_map <char,int> mp;
        //insert all chararacter with thier respective frequency
        for(char i : text){
            mp[i]++;
        }
        //find the minimum frequency of any character of balloon;       
        for(int i=0;i<s.size();i++){
            int count=0;
            if(i>1 && i<6){
                count=mp[s[i]]/2;
            }else{
                count=mp[s[i]];
            }
            res=min(res,count);
        }

        return res;

        
    }
};
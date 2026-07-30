class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int> mp;
        for(auto i : magazine){
            mp[i]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(mp[ransomNote[i]]<1){
                return false;
            }
            else{
                mp[ransomNote[i]]--;
            }
        }

        return true;
        
    }
};
class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map <char,int> mp;
        queue <char> q;

        for(int i=0;i<s.size();i++){
            q.push(s[i]);
            mp[s[i]]++;
        }

        for(int i=0;i<s.size();i++){
            char c=q.front();
            q.pop();
            if(mp[c]==1){
                return i;
            }
        }

        return -1;

        
    }
};
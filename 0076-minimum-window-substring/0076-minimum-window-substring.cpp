class Solution {
public:
    bool sahi(vector<int> &have, vector<int> &need){
    for(int i=0;i<256;i++)
    {
        if(have[i]<need[i])
        return false;
    }
    return true;
    }

    string minWindow(string s, string t) {

        vector<int> need(256, 0);
        vector<int> have(256, 0);
        int m=t.size(),n=s.size();

        if(m>n){
            return "";
        }

        for(int i=0;i<m;i++)
        need[t[i]]++;

        int low=0,high=0,res=INT_MAX,start;

        for(high=0;high<n;high++){

            have[s[high]]++;

            while(sahi(have,need)){

                int len=high-low+1;

                if(res>len){
                    res=len;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }
        
        return (res==INT_MAX)? "" : s.substr(start,res);
    
    
    }
};
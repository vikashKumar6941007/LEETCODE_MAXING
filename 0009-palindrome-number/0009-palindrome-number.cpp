class Solution {
public:
  
    bool isPalindrome(int x) {
        if(x<0){return 0;}

          int real=x;
          int k=0;

        while(x!=0){
       
        int a=x%10;
        x=x/10;

        if((k>INT_MAX/10)|| (k<INT_MIN/10)){
            return 0;
            }
            
        k=k*10+a;
        }
       return real==k;


    }
};
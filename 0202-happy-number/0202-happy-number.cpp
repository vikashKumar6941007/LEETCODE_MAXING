class Solution {
public:
    int digit_sqr(int n){
        int sum=0,k=0;
        while(n!=0){
            k=n%10;
            n=n/10;
            sum=sum+(k*k);
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;

        while(fast!=1){
            
        slow=digit_sqr(slow);
        fast=digit_sqr(digit_sqr(fast));
    
        if(slow==fast and slow!=1)
        return 0;
        }
        return 1;

    }
};
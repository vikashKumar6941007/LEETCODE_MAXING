class Solution {
public:
 //returns sum of squares of digit of that number
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
        // check condition
        while(fast!=1){
        //slow move 1 step while fast move 2 step at a time           
        slow=digit_sqr(slow);
        fast=digit_sqr(digit_sqr(fast));
        //when loop is found but that loop is not of number 1
        if(slow==fast and slow!=1)
        return 0;
        }
        return 1;
    }
};
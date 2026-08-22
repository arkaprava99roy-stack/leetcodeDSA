class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int r = 0;
        int babor = n;
        while ( n > 0 ){
            r = n % 10;
            sum += r;
            product *= r;
            n /= 10;
        }
        sum += product ;
        if( babor % sum == 0)
           return true;
        else 
           return false;

    }
};
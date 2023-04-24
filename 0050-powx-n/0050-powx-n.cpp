class Solution {
public:
    int max1  = INT_MAX -1;
    double max = (double)max1;
    double myPow(double x, int n) {
       
        if(n == 0){
            return 1;
        }
        
        
        
        if(n < 0){
           n = abs(n);
           x = 1/x;
        }
        
        if(abs(n) == 1){
            return x;
        }
        
        double takeValue = myPow(x,n/2) ;
        takeValue *= takeValue;
        if(n%2  != 0){
            return takeValue * x;
        }
       
        return takeValue;
    }
};
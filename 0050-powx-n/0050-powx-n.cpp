class Solution {
private:
    double power(double x, int n){
            if(n == 0)
            return 1;
            
            if(n == 1)
            return x;

            double ans = power(x, n/2);

            if(n % 2 == 0){
                return ans * ans;
            }

            else{
                return x * ans * ans;
            }
        }
public:

    double myPow(double x, int n) {
        double ans = power(x,n);
        if(n<0){
            ans = 1/ans;
        }
        return ans;
    }
};
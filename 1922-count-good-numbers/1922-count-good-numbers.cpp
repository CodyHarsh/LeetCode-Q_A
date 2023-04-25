// class Solution {
// public:
//     int mod = 1000000007;
//     long long findPow(long long n, long long x){
//         if(x == 0){
//             return 1;
//         }
        
        
//         long long ans = findPow(n,x/2);
//         ans *= ans;
//         ans %= mod;
        
//         if(x%2 != 0){
//             ans =( ans * n) % mod;
//         }
//         return ans;
//     }
//     int countGoodNumbers(long long n) {
//         int powerOfEven = n/2 + n%2;
//         int powerOfOdd = n/2;
        
//         return (findPow(5, powerOfEven)%mod * findPow(4,powerOfOdd)%mod)%mod;
        
//     }
// };




#define mod 1000000007
class Solution {
private:
    long long power(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= mod;
        if(n%2==1){
            ans *= x;
            ans %= mod;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n/2;
        long long numberOfEvenPlaces = n/2 + n%2;
        return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces))%mod;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = (n*(n+1))/2;
        int givenSum = 0;
        for(auto i: nums){
            givenSum += i;
        }
        
        return totalSum - givenSum;
    }
    
};
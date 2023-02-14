class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int min = nums[0];
        int maxi = 0;
        for(int i =1; i<nums.size(); i++){
            if(nums[i] > min) {
                int diff = nums[i] - min;
                if(diff > maxi)
                maxi = diff;
            }else{
                min = nums[i];
            }
        }
        return maxi;
    }
};
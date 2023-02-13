class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //Boyer More Algorithm: 

        int maxValue = 0;
        int weightage = 0;
        for(int i = 0; i<nums.size(); i++){
            if(maxValue == nums[i]){
                weightage++;
            }
            else if(weightage == 0){
                maxValue = nums[i];
                weightage = 1;
            }
            else{
                weightage--;

            }
        }
        return maxValue;
    }
};
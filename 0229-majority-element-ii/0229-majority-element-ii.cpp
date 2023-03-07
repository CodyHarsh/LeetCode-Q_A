class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;

        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        //Finding the 2 largest frequency elements
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == num1){
                count1++;
            }else if(nums[i] == num2){
                count2++;
            }else if(count1 == 0){
                num1 = nums[i];
                count1 =1;
            }else if(count2 == 0){
                num2 = nums[i];
                count2= 1;
            }else{
                count1--;
                count2--;
            }
        }
        
        
        //Counting that both num1 and num2 appears more than n/3 times
        count1 = 0;
        count2 = 0;
        for(int i= 0; i<nums.size(); i++){
            if(num1 == nums[i]){
                count1++;
            }
            if(num2 == nums[i]){
                count2++;
            }
        }
        
        int nDivideBy3 = (nums.size()/3);
        if(num1 == num2){
            ans.push_back(num1);
            return ans;
        }
        
        if(count1 > nDivideBy3){
            ans.push_back(num1);
        }
        if(count2 > nDivideBy3){
            ans.push_back(num2);
        }
        return ans;
    }
};
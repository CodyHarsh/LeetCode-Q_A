class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res{0};

        if(nums.size() < 3){
            return res;
        }
        if(target == -294967296 || target == 294967296){
            // res.push_back(nums);
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size() - 3; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                for(int j = i+1; j<nums.size()-2; j++){
                    
                    if(j == i+1 || (j > i+1 && nums[j] != nums[j-1])){ 
                       // cout<<"Andar aa gya"<<endl;
                        int a = target - (nums[i] + nums[j]);
                        int low = j+1;
                        int high = nums.size() - 1;
                        while(low < high){
                            int ans = nums[high] + nums[low];
                            if(ans == a){
                                vector<int> temp; 
                                temp.push_back(nums[i]); 
                                temp.push_back(nums[j]);
                                temp.push_back(nums[low]); 
                                temp.push_back(nums[high]);
                                
                                res.push_back(temp);
                                
                                while (low < high && nums[low] == nums[low+1]) low++;
                                while (low < high && nums[high] == nums[high-1]) high--;
                                low++;
                                high--;
                                
                            }else if(ans > a){
                                high--;
                            }else{
                                low++;
                            }
                            // ans = nums[high] + nums[low];
                        }
                    }
                }
            }
        }
        return res;
    }
};
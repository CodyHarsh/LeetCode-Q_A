class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int start = nums[0][0];
        int end = nums[0][1];
         // for(int i = 0; i<nums.size(); i++){
         //     cout<<"i: "<<nums[i][0]<<" j: "<<nums[i][1]<<endl;
         // }
        for(int i = 1; i<nums.size(); i++){
            //cout<<"entered: "<<start<<" ENd: "<<end<<endl;
            if(nums[i][0] <= end && nums[i][1] >= start){
                if(nums[i][0] < start){
                    start = nums[i][0];
                }
                if(nums[i][1] > end){
                    end = nums[i][1];
                }
            }else{
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                
                start = nums[i][0];
                end = nums[i][1];
            }

        }
        
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
        return ans;
    }
};
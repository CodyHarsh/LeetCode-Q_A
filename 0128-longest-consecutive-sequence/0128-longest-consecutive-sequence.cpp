class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> map;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = false;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(map.find(nums[i]-1) != map.end()){
                map[nums[i]] = true;
            }
        }
        
        for(auto i: map){
            if(i.second == false){
                int current = (i.first) + 1;
                int currMax = 1;
                while(map.find(current) != map.end()){
                    currMax++;
                    current++;
                }
                if(count < currMax){
                    count = currMax;
                }
            }
        }
        return count;
    }
};
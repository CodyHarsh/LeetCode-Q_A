class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int ,int> map;
        for(auto i: nums){
            map[i] ++;
        }

        int totalCount = 0 ;
        for(auto i: map){
            int freq = i.second;
            cout<<i.second<<" ";
            if(freq == 1){
                return -1;
            }
            if(freq % 3 == 0){
                totalCount += freq/3;
            }else{
                int two = (freq - 2)%3 ;
                int four = (freq - 4)%3;
                if(two == 0) {
                    totalCount  = totalCount + ((freq-2)/3) + 1;
                }else{
                    totalCount  = totalCount + ((freq-4)/3) + 2;
                }
            }
            cout<<totalCount<<endl;
        }
        return totalCount;
    }
};

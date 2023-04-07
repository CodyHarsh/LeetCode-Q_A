class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char ,int> map;
        int count = 0;
        for(int i = 0; i<jewels.size(); i++){
            map[jewels[i]]++;
        }
        
        
        for(int i = 0; i<stones.size(); i++){
            if(map.find(stones[i]) != map.end()){
                count++;
            }
        }
        
        return count;
    }
};
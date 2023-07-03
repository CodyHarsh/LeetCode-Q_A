class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        bool check = false;
        unordered_map<char, int> map;
        int firstIndex = -1;
        int i = 0, j = 0;
        
        while(i < s.size() && j< goal.size()){
            map[s[i]]++;
            if(map[s[i]] >=2){
                check = true;
            }
            if(s[i] != goal[j]){
                if(firstIndex == -1){
                    firstIndex = i;
                }else{
                    swap(s[i], s[firstIndex]);
                    return (s== goal);
                }
            }
            
            i++; j++;
        }
        
        if(firstIndex != -1){
            return false;
        }
        if(check){
            return true;
        }
        
        
        return false;
        
        
    }
};
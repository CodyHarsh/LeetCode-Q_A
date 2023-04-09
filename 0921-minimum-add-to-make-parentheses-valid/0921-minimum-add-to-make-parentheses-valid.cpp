class Solution {
public:
    int minAddToMakeValid(string s) {
        //Using Stack Hoga starting wale karne hai

        int count = 0 , ans = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                count++;
            }else if(s[i] == ')'){
                count--;
            }
            if(count < 0){
                ans += abs(count);
                count = 0;
            }
        }
        return ans + abs(count);
    }
    
    
};
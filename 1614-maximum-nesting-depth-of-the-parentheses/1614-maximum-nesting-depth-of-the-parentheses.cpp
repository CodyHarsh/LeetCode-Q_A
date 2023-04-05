class Solution {
public:
    int maxDepth(string s) {
        int maxBracket = 0;
        int curr = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                curr++;
            }else if(s[i] == ')'){
                maxBracket = max(maxBracket, curr);
                curr--;
            }
        }
        return maxBracket;
    }
};
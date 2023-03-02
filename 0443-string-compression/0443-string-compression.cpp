class Solution {
public:
    //Conversion of a integer value into char
    void conversionIntToChar(int value, vector<char>& ans){
        int temp =  value;
        vector<char> valueStored;
        while(temp){
            int store = temp%10;
            //Converting the last value into the integer:
            char finalValue = '0' + store;
            valueStored.push_back(finalValue);
            temp /=10;
        }
        
        for(int i = valueStored.size()-1; i>=0; i--){
            ans.push_back(valueStored[i]);
        }
    }
    
    int compress(vector<char>& chars) {
        vector<char> ans;
        //If we have the base case as 1
        if(chars.size() == 1){
            return 1;
        }
        
        char prev = chars[0];
        int count = 1;
        
        for(int i = 1; i<chars.size(); i++){
            if(chars[i] == prev){
                count++;
            }
            else{
                ans.push_back(prev);
                
                if(count != 1){
                    conversionIntToChar(count, ans);
                }
                
                prev = chars[i];
                count = 1;
            }
        }
         ans.push_back(chars[chars.size()-1]);
         if(count != 1){
            conversionIntToChar(count, ans);
         }
        chars = ans;
        
        return ans.size();
     }
};
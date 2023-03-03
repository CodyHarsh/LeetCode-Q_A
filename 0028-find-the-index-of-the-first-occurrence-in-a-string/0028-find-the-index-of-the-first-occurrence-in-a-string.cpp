class Solution {
public:
    
    //Time Complexity:O(n^2);
    int strStr(string haystack, string needle) {
        for(int i = 0; i<haystack.size(); i++){
            if(haystack[i] == needle[0]){
                int j = 0;
                int z = i;
                while(j<needle.size()){
                    if(needle[j] != haystack[z]){
                        break;
                    }else{
                        j++;
                        z++;
                    }
                }
                
                if(j == needle.size()){
                    return i;
                }
            }
            
        }
        
        return -1;
    }
};
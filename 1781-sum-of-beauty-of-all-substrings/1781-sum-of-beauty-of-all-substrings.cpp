class Solution {
public:
    int beautySum(string s) {
        
        int  n =s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            
            int a[26] = {0};
            int max = INT_MIN;
            int  min = INT_MAX;
            for(int j = i; j<n; j++){

                bool distinct = false;
                int indexOfS = s[j] - 'a';
                a[indexOfS] ++;
                
                if(max < a[indexOfS]){
                    max = a[indexOfS];
                }
                min = a[indexOfS];
                
                for(int k = 0; k<26; k++){
                    if(a[k] < min && a[k] >=1){
                        min = a[k];
                    }
                }
                ans += (max - min);
            } 
        }
        
        return ans;
        
    }
};
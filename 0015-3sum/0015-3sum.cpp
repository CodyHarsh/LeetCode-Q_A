class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
       
        vector<vector<int>> res; 
        
        //First sort the array
        sort(num.begin(), num.end()); 
        
        // moves for a
        for (int i = 0; i < (int)(num.size())-2; i++) {
            //So we don't have to duplicate triplets that's why it is written
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {
                
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    
                    if (num[lo] + num[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        
                        //We also don't have tor return the same type of data in the triplets
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};
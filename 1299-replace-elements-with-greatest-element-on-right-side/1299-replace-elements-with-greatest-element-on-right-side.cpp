class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        vector<int> ans;
        int n = a.size();
        int currMax = a[n-1];
        ans.push_back(-1);
        for(int i = n-2; i>=0; i--){
            if(currMax <=  a[i]){
                ans.push_back(currMax);
                currMax = a[i];
            }else{
                ans.push_back(currMax);
            }
        }
       
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
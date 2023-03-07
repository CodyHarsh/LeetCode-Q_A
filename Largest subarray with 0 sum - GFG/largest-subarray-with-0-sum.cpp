//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n){ 
        //15 13 7 8 15 25 48
        // Your code here:
        unordered_map<int, int> map;
        int num = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            
            if(sum == 0){
                num = max(num, i+1);
            }
            if(map.find(sum) == map.end()){
                map[sum] = i;
            }
            else{
                int startValue = map[sum];
                int end = i;
                if(end -startValue > num){
                    num = end - startValue;
                }
            }
        }
        return num;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
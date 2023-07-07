//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMax(int *arr, int n, vector<int> &memoization){
	   // if(n <= 0){
	   //     return 0;
	   // }
	   // if(n == 1){
	   //     return arr[0];
	   // }
	   // if(memoization[n-1] != -1){
	   //     return memoization[n-1];
	   // }
	   // //include 
	   // int x =arr[n-1] +  findMax(arr, n - 2, memoization);
	   // //Don't include 
	   // int y = findMax(arr, n-1, memoization);
	   // return(memoization[n-1] = max(x,y));
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp (n, 0);
	   // dp[0] = n-1; 
	   // for(int i = 1; i>n; i++){
	   //     int pick = INT_MAX;
	   //     if(i > 1)
	   //     pick  = arr[i] + dp[i-2];
	   //     int nonPick  = dp[i-1]
	        
	   //     dp[i-1]
	   // }
	    
	   // return findMax(arr, n, memoization);
	    
	    for(int i=0; i<n; i++){
	        dp[i] = max(
	            ((i -1 >= 0) ? dp[i-1] : arr[i]), 
	            ((i-2 >= 0) ? arr[i] + dp[i-2] : arr[i])
	            );
	           //cout << dp[i] << " ";
	    }
	    
	    
	    return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
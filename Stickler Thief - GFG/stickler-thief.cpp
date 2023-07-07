//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int findMax(int arr[], int n, vector<int> &dp){
        if(n <= 0) return 0;
        if(n==1){
            return arr[n-1];
        }
        if(dp[n-1] != -1) return dp[n-1]; 
        int left = findMax(arr, n-1, dp);
        int right = INT_MIN;
        if(n > 1)
        right = arr[n-1] + findMax(arr, n-2,dp);
         (dp[n-1] = max(left, right));
         return dp[n-1];
    }
    int FindMaxSum(int arr[], int n)
    { 
        // if(n <= 0) return 0;
        // if(n==1){
        //     return arr[n-1];
        // }
        
        // int left = FindMaxSum(arr, n-1);
        // int right = INT_MIN;
        // if(n > 1)
        // right = arr[n-1] + FindMaxSum(arr, n-2);
        // return max(left, right);
        
        vector<int> dp(n,-1);
        dp[0] = arr[0];
        for(int i = 1; i<n; i++){
            int left = dp[i-1];
            int right = arr[i];
            if(i > 1)
            right = arr[i] + dp[i-2];
            
            dp[i] = max(left, right);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
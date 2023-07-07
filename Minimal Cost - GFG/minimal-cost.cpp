//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n, -1);
        dp[0]=  0;
        for(int i = 1; i<height.size(); i++){
            int x = INT_MAX;
            for(int j = i-1; j>=i-k; j--){
                if(j>= 0)
                x = min (dp[j] + abs(height[i] - height[j]), x);
                else
                break;
            }
            dp[i] = x;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
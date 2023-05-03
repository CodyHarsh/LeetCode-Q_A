//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> generate(int num){
        vector<string> s;
        string ak;
        if(num == 1){
            ak ='1';
            s.push_back(ak);
            ak = '0';
            s.push_back(ak);
            return s;
        }
        
        
        s = generate(num - 1);
        int  n =s.size();
        for(int i = 0; i<n; i++){
            ak = s[i];
            if(ak[ak.size() - 1] == '0'){
                s[i] += '0';
                //s[i] = ak;
                ak += '1';
                s.push_back(ak);
            }else{
                s[i] += '0';
            }
        }
        return s;
        
        
    }
    void generateBinaryStrings(int num){
        //Write your code:
        vector<string> ans = generate(num);
        sort(ans.begin(), ans.end());
        for(int i =0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
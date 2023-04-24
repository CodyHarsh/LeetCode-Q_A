//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++

string reverseload (string str, int i, int j) {
    if(i==j || i>=j){
        return str;
    }
    swap(str[i],str[j]);
    return reverseload(str, ++i, --j);
    
}
string reverseWord(string str){
    return reverseload(str, 0, str.size()-1);
    
}


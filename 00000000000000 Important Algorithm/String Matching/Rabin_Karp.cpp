#include<bits/stdc++.h>
using namespace std;


long long m = pow(10,9) + 9;
long long p1 = 10;


long long hashValueCalculate(string k){
    long long ans = 0;
    int tenthValue = k.size() -1;
    for(int i = 0; i<k.size(); i++){
        long long rollinCode = k[i] - 'a' + 1;
        ans += (rollinCode * pow(p1,tenthValue));
        tenthValue--;
    }
    
    return (ans % m);
}

bool rotateString(string t, string p) {
    if(p.size() > t.size()){
        return 0;
    }
    //step 1: hash Value of Pattern.size()
    long long patternHash = hashValueCalculate(p);

    //Step 2: Calculate the value of first text pattern.size() hashvalue;
    int pSize = p.size();
    long long currentHash = hashValueCalculate(t.substr(0,pSize));
    
    for(int i = 0; i<=t.size() - pSize; i++){
        //Step 2.1 It will first Check the value of currentHash in first iteration than it will go to the next 
      //In this I have not created the modulo for the final 
        if(i >= 1){
            //Step 2.1.1 Now we will be substracting the hashValue 0f ith 
            long long ithValueHash =t[i-1] - 'a' + 1; 
            long long ithValue =  ithValueHash * pow(p1 , pSize - 1);
            currentHash = ((currentHash - ithValue)*p1) + (t[i+pSize-1] - 'a' + 1);
        }
        //Step2.2 Check Whether  the hashValue are equal or not 
        //If they are equal check it the pattern is matching with text or not
        
        
        string temp = t.substr(i,pSize);
        
        if(currentHash == patternHash && temp == p){
             return true;
        }
        
    }
    
    return false;


}


int main(){
    //t = text p = pattern
    string p,t;
    cin>>t>>p;
    
    bool ans = rotateString(t,p);
    if(ans){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}

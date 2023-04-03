#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void badTable(vector<int> &z ,  string temp){
    // Step 4:
    int count = 1;
    int lastCompare = 0;
    
    for(int i = 1; i<temp.size(); i++){
        if(temp[i] == temp[lastCompare]){
            z[i+1] = count;
            count++;
            lastCompare++;
        }else{
            lastCompare = 0;
            count = 1;
        }
    }
}

bool knuthAlgorithm(string t, string p){

    //Step 1: Find the table for the kmp pattern
    vector<int> z(p.size() + 1 , 0);
    badTable(z, p);
    string temp = ' '+ p;
    //Step 2: Compare with the text and the bad table
    int i = 0;
    int j = 0;
    while(j < p.size()+ 1 && i < t.size()){
        if(temp[j+1] == t[i]){
            j++;
            i++;
        }else if(t[i] != temp[j+1 ] && j > 0){
             j = z[j];
             continue; 
        }else{
            i++;
        }
        // if(i == p.size()+1 && t.size() != j){
        //     return true;
        
    }
    if(j == p.size()){
        return true;
    }
    return false;

}

int main(){
    string t,p;
    cin>>t>>p;
    bool ans = knuthAlgorithm(t,p);
    if(ans){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
}

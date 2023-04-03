#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Zcalculate(vector<int> &z ,  string temp){
    // Step 4:
    z[0] = 0;
    for(int i = 1; i<temp.size(); i++){
        int count = 0;
        int k = 0;
        int loop = i;
        while(loop != temp.size() && temp[loop] == temp[k]){
            count++;
            loop++;
            k++;
        }
        
        z[i] = count;

        k = 1;
        int temp = i + 1;
        count --;
        while(count > 0){
            z[temp] = z[k];
            k++;
            count--;
            temp++;
        }

        if(loop != i){
            i = loop-1;
        }
    }
}

bool knuthAlgorithm(string t, string p){

    //Step 1: Add and unique letter between the seperation of 
    string temp = p + '#' + t;
    int x = temp.size();

    //Step 2: Make the z array and store the inital value as 0
    vector<int> z(x , 0);
    
    //Step 3: Traverse the arrray and insert the value in the z array:
    Zcalculate(z, temp);

    //Step 4: Match the z is having the pattern in it or not
    for(int i = 0; i<temp.size(); i++){
        if(z[i] == p.size()){
            return true;
        }
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

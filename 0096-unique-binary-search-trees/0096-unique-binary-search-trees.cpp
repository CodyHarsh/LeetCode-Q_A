class Solution {
public:
    int numTrees(int n) {
        //Find the catalan number from 1 to n
        
        vector<long long> temp(n+1, 1);
        for(int i = 2; i<=n; i++){
            int currX = 0, currY = i -1;
            long long sum= 0;
            while(currX < i && currY >= 0){
                sum = sum + (temp[currX]* temp[currY]);
                currX++;
                currY--;
            }
            temp[i] = sum;
        }
        
        
        return temp[n];
    }
};
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increase = true;
        bool decrease = true;
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i] > A[i+1]) increase = false;
            if(A[i] < A[i+1]) decrease = false;
            if(increase == false && decrease == false) return false;
        }
        return true;
        
//         if(inc == nums.size() - 1 || dec == nums.size() -1){
//             cout<<inc << " "<<dec<<endl;
//             return true;
            
//         }
//         return false;
    }
};
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
//         int start = 0;
//         int end= arr[0]-1;
//         int count = 0;
//         int firstStart = 1;
//         for(int i = 0; i<arr.size(); i++){
//             if(count >= k){
//                 break;
//             }
//             // if(nums[i] == firstStart){
//             //     firstStart++;
//             // }else{
//             //     firstStart = -1;
//             //     start = firstStart;
//             //     end = nums[i]-1;
//             //     count += nums[i] - start
//             // }
//            // int val1 = ans[0];
//             if(i-1 == -1 && arr[0] > 1){
//                 start = 1;
//                 end = arr[0]-1;
//                 count += (start -arr[0]);
//                  cout<<"first "<<count<<endl;
//             }else if (arr[i-1]+1 != arr[i]){
//                 start = arr[i-1] ;
//                 end = arr[i] -1;
//                 count += (arr[i] - arr[i-1] -1);
//                  cout<<arr[i]<<" : "<<count<<endl;
//             }
           
//         }
        
//         if(count >= k){
//             int ans1 = abs(count - (end - start));
//             return start + (abs(ans1-k));
//         }else if(count == 0){
//             return arr[arr.size() - 1] + k;
//         }
//         return 0;
        int count = arr[0] -1;
        cout<<count<<endl;
        if(count >=k){
            return k;
        }
        int start = 0;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i-1]+1 != arr[i]){
                start = arr[i];
                int ans = count + ((arr[i]- arr[i-1]) -1);
                
                cout<<i<<" i: "<<ans<<endl;
                if(ans >= k){
                    cout<<"Yahan par aa raha hu";
                    cout<<count - k<<endl;
                    cout<<count<<endl;
                    return arr[i-1] + abs(count- k);
                }
                count = ans;
            }
            
        }
       
        
        return arr[arr.size() - 1] + abs(count - k);
        
        
    }
};
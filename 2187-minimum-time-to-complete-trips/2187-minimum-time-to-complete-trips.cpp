class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //Maximum element with the maximum trips required
        
        long long max = (long long)(*max_element(time.begin(), time.end())) * totalTrips;//34
        long long min = 1; // 18
        
        while(min < max){
            long long mid = min + (max - min)/2; //26
            long long sum = 0; //
            for(int i =0; i<time.size(); i++){
                sum += (mid/time[i]); // 
            }
            // cout<<"SUM: "<<sum<<" max: "<<max<<" min:"<<min<<endl;
            if(sum >= totalTrips){
                // if total trip can be done
                // check for more lower time
                max = mid;
            }else{
                // if it is not able to make trip go 
                // for upper time
                min = mid + 1;
            }
        }
        // return minimum time
        
        return min;
//         long long sum = -1;
//         int i = 1;
//         while(sum != totalTrips){
//             long long trips = 0;
//             for(int j = 0;j<time.size();j++){
//                 //i/j
//                 trips = trips + (i/time[j]); 
//             }
//             sum = trips;
//             i++;
//             if( totalTrips%sum != 0){
//                 break;
//             }
//         }
        
//         return (i-1) * totalTrips/sum;
        // Input: time = [1,2,3], totalTrips = 5
        // Output: 3
        
    }
};
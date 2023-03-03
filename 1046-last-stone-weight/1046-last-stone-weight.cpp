class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //O(nlogn): From sorting we can do.
        
        //Priority queue is queue data structure for implementation
        //Heap uses tree structure and in sorting way
        priority_queue<int> ans;
        for(auto i: stones){
            ans.push(i);
        }
        
       
        while(ans.size() > 1){
             int a = ans.top();
             ans.pop();
             int y = ans.top();
             ans.pop();
             if(a!= y){
                 ans.push(a-y);
             }
        }
        if(ans.empty()){
            return 0;
        }
        return ans.top();
        
    }
};
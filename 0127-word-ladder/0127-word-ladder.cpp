class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string, int>> q;
        
        set<string> checking;
        
        for(int i = 0; i<wordList.size(); i++){
            checking.insert(wordList[i]);
        }
        
            
        
        q.push({beginWord,1});
        checking.erase(beginWord);
        
        while(!q.empty()){
        
            int dist = q.front(). second;
            string s = q.front().first;
            cout<<"dist: "<<dist<<" string: "<<s<<endl;
            q.pop();
            
            if(s == endWord){
                return dist;
            }
            
            //Check each value from a to z expect the current value:
            for(int i = 0; i<s.size(); i++){
                string temp = s;
                
                //Traversing each value from a to z:
                for(char j = 'a'; j<='z'; j++){
                    if(temp[i] == j){
                       // i++;
                        continue;
                    }
                    temp[i] = j;
                    if(checking.find(temp) != checking.end()){
                        q.push({temp, dist+1});
                        checking.erase(temp);
                    }
                }
                
            }
            
            
        }
              
              return 0;
        
    }
};
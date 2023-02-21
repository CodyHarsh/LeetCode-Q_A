class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>(numRows);
        
        for(int i = 1; i<=numRows; i++){
            List<Integer> help = new ArrayList<Integer>(i);
            for(int j = 0; j<i; j++){
                if(j == 0 || j == i-1){
                    help.add(1);
                }else{
                    int k = i -2;
                    help.add(ans.get(k).get(j) + ans.get(k).get(j-1));
                }
            }
            ans.add(help);
        }
        return ans;

        
        
    }
}
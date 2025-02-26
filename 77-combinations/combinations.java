class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> l=new ArrayList<>();
        backTrack(l,n,k,0,new ArrayList<>());
        return l;
    }
    private void backTrack(List<List<Integer>> l,int n,int k,int index,List<Integer> ls){
        if(ls.size()==k ){
           l.add(new ArrayList<>(ls));
           return;
        }
        for(int i=index;i<n;i++){
            ls.add(i+1);
            backTrack(l,n,k,i+1,ls);
            ls.remove(ls.size()-1);
        }
        return; 
    }
}
// BFS of Graph (Easy)
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Correct 2025-08-04 21:11:17 | Java

class Solution {
    // Function to return Breadth First Search Traversal of given graph.
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        // code here
        ArrayList<Integer> visited = new ArrayList<>();
        ArrayList<Integer> res = new ArrayList<>();
        Queue<Integer> bfs = new LinkedList<>();
        
        bfs.add(0);
        visited.add(0);
        while(!bfs.isEmpty()){
            Integer node = bfs.poll();
            res.add(node);
            
            for(int neighbour : adj.get(node)){
                if(!visited.contains(neighbour)){
                    bfs.add(neighbour);
                    visited.add(neighbour);
                }
            }
        }
        return res;
    }
}
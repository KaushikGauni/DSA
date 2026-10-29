// Pascal's Triangle
// https://leetcode.com/problems/pascals-triangle/
// Accepted 2023-06-21 | Runtime 1 ms | Memory 41.3 MB

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> allrows = new ArrayList<List<Integer>>();
	ArrayList<Integer> row = new ArrayList<Integer>();
	for(int i=0;i<numRows;i++)
	{
		row.add(0, 1);
		for(int j=1;j<row.size()-1;j++)
			row.set(j, row.get(j)+row.get(j+1));
		allrows.add(new ArrayList<Integer>(row));
	}
	return allrows;
}
}
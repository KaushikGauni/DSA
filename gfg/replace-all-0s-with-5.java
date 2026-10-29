// Replace all 0's with 5 (Basic)
// https://www.geeksforgeeks.org/problems/replace-all-0s-with-5/1
// Correct 2022-11-20 11:43:07 | Java



class GfG {
    int convertfive(int num) {
        // Your code here
        String st = Integer.toString(num);
        String res = st.replaceAll("0","5");
        int ans = Integer.parseInt(res);
        return ans;
    }
}
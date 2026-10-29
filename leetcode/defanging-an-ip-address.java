// Defanging an IP Address
// https://leetcode.com/problems/defanging-an-ip-address/
// Accepted 2022-08-17 | Runtime 0 ms | Memory 41.3 MB

class Solution {
    public String defangIPaddr(String address) {
        String a="";
    	if(address.contains(".")) {
        	a = address.replace(".", "[.]");
        }
        
        return a;
    }
}
// Multiply Two Linked Lists (Hard)
// https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1
// Correct 2026-09-27 11:20:19 | C++

/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int key) {
        data = key;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int multiplyTwoLists(Node* first, Node* second) {
        // code here
        const int MOD = 1000000007;
        long long num1 = 0, num2 = 0;
        Node* temp1 = first, *temp2 = second;
    
        while(temp1){
            num1 = (num1 * 10 + temp1->data) % MOD;
            temp1 = temp1->next;
        }
        while(temp2){
            num2 = (num2 * 10 + temp2->data) % MOD;
            temp2 = temp2->next;
        }
        return (num1 * num2) % MOD;
        
    }
};
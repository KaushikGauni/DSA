// Linked List in Zig-Zag fashion (Medium)
// https://www.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1
// Correct 2026-09-27 14:07:58 | C++

/* Structure of a link list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* zigZag(Node* head) {
        // code here
        if(!head){
            return head;
        }
        
        vector<Node*> arr;
        for(Node* temp = head;temp;temp=temp->next){
            arr.push_back(temp);
        }
        
        sort(arr.begin(), arr.end(), [](Node* a, Node* b){
            return a->data < b->data;
        });
        
        int i = 0, j = arr.size()-1;

        while(i<j){
            arr[i]->next = arr[j];
            i++;
            if(i==j){
                break;
            }
            arr[j]->next = arr[i];
            j--;
        }
        arr[i]->next = nullptr;
        
        return arr[0];
    }
};
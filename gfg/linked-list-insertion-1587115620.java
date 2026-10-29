// Linked List End Insertion (Basic)
// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1
// Correct 2023-07-23 21:14:01 | Java



/*
class Node{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
}
*/
class Solution
{
    //Function to insert a node at the beginning of the linked list.
    Node insertAtBeginning(Node head, int x)
    {
        // code here
        Node newNode = new Node(x);
        newNode.next = head;
        head = newNode;
        return head;
    }
    
    //Function to insert a node at the end of the linked list.
    Node insertAtEnd(Node head, int x)
    {
        // code here
        
        Node newNode = new Node(x);
        if(head==null){
            return newNode;
        }
        Node temp = head;
        while(temp.next!=null){
            temp = temp.next;
        }
        temp.next = newNode;
        return head;
    }
}
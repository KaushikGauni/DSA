// Two Stacks in Array (Medium)
// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1
// Correct 2026-09-09 09:30:54 | C++

class twoStacks {
    int arr[100];
    int size = 100;
    int top1, top2;

  public:
    twoStacks() {
        // Initialize the top pointers of both stacks
        top1 = 0;
        top2 = 99;
    }

    void push1(int x) {
        // Insert the given element at the top of the first stack
        arr[top1++] = x;
    }

    void push2(int x) {
        // Insert the given element at the top of the second stack
        arr[top2--] = x;
    }

    int pop1() {
        // Remove and return the top element of the first stack
        // Return -1 if the stack is empty
        if(top1==0){
            return -1;
        }
        return arr[--top1];
    }

    int pop2() {
        // Remove and return the top element of the second stack
        // Return -1 if the stack is empty
        if(top2==99){
            return -1;
        }
        return arr[++top2];
    }
};
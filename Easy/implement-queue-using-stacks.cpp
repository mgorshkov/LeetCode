//232. Implement Queue using Stacks
//Easy
//
//3278
//
//223
//
//Add to List
//
//Share
//Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
//
//Implement the MyQueue class:
//
//void push(int x) Pushes element x to the back of the queue.
//int pop() Removes the element from the front of the queue and returns it.
//int peek() Returns the element at the front of the queue.
//boolean empty() Returns true if the queue is empty, false otherwise.
//Notes:
//
//You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
//Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
//
//
//Example 1:
//
//Input
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//Output
//[null, null, null, 1, 1, false]
//
//Explanation
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false
//
//
//Constraints:
//
//1 <= x <= 9
//At most 100 calls will be made to push, pop, peek, and empty.
//All the calls to pop and peek are valid.

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        moveStacks(st1, st2);
        auto el = st2.top();
        st2.pop();
        moveStacks(st2, st1);
        return el;
    }
    
    int peek() {
        moveStacks(st1, st2);
        auto el = st2.top();
        moveStacks(st2, st1);
    
        return el;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
    
private:
    void moveStacks(stack<int>& s1, stack<int>& s2) {
        while (!s1.empty()) {
            auto el = s1.top();
            s1.pop();
            s2.push(el);
        }
    }
    
    stack<int> st1;
    stack<int> st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

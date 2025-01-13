#include <iostream>
#include "Stack_Linkedlist.h"

using namespace std;

int main() {
    // Test push function
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    cout << "After pushing 10, 20, 30, 40: ";
    stack.display(); // Display the stack

    // Test peek function
    cout << "Peek top element: " << stack.peek() << endl;

    // Test size function
    cout << "Size of stack: " << stack.size() << endl;

    // Test pop function (without reference value)
    stack.pop();
    cout << "After popping one element: ";
    stack.display();

    // Test pop function (with reference value)
    int poppedValue;
    stack.pop(poppedValue);
    cout << "After popping another element, popped value: " << poppedValue << endl;
    stack.display();

    // Test isEmpty function
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Test clear function
    stack.clear();
    cout << "After clearing the stack: ";
    stack.display();

    // Test contains function
    stack.push(50);
    stack.push(60);
    cout << "Does stack contain 50? " << (stack.contains(50) ? "Yes" : "No") << endl;
    cout << "Does stack contain 100? " << (stack.contains(100) ? "Yes" : "No") << endl;

    // Test reverse function
    stack.reverse();
    cout << "After reversing the stack: ";
    stack.display();

    // Test clone function
    Stack<int> clonedStack = stack.clone();
    cout << "Cloned stack: ";
    clonedStack.display();

    // Test swap function
    Stack<int> anotherStack;
    anotherStack.push(70);
    anotherStack.push(80);
    cout << "Another stack before swap: ";
    anotherStack.display();

    stack.swap(anotherStack);
    cout << "After swapping stacks: " << endl;
    cout << "Original stack: ";
    stack.display();
    cout << "Another stack: ";
    anotherStack.display();

    // Test toArray function
    int* array = stack.toArray();
    int size = stack.size();
    cout << "Array representation of stack: [";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Don't forget to free the memory when using the array
    delete[] array;

    return 0;
}

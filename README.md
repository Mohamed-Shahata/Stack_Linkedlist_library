# Stack Implementation Using Linked List

This repository contains an implementation of a Stack data structure using a linked list. The stack supports various operations such as push, pop, peek, size, reverse, and more.

## Structure

The stack is implemented using a linked list where each node contains the data and a pointer to the next node. The `Stack` class provides methods for stack manipulation and utility functions.

### Node Structure

Each `Node` consists of:
- `data`: The data element stored in the node (of type `T`).
- `next`: A pointer to the next node in the stack.

### Methods

#### 1. `Stack()`
Constructor to initialize an empty stack with `top` set to `nullptr`.

#### 2. `~Stack()`
Destructor that clears the stack by deleting all nodes and freeing the memory.

#### 3. `void push(T value)`
Adds a new element to the top of the stack.

- **Parameters**: `value` - The value to be added to the stack.
- **Operation**: Creates a new node, assigns the value to it, and links it to the top of the stack.

#### 4. `void pop()`
Removes the top element of the stack.

- **Throws**: `underflow_error` if the stack is empty.
- **Operation**: Removes the top node and updates the top pointer to the next node.

#### 5. `void pop(T &value)`
Removes the top element from the stack and assigns its value to the provided reference `value`.

- **Parameters**: `value` - A reference to store the popped value.
- **Throws**: `underflow_error` if the stack is empty.
- **Operation**: Removes the top node, assigns its value to `value`, and updates the top pointer.

#### 6. `T peek() const`
Returns the top element of the stack without removing it.

- **Throws**: `underflow_error` if the stack is empty.
- **Operation**: Returns the data of the top node.

#### 7. `bool isEmpty() const`
Checks if the stack is empty.

- **Returns**: `true` if the stack is empty, `false` otherwise.

#### 8. `int size() const`
Returns the number of elements in the stack.

- **Returns**: The size of the stack.

#### 9. `void clear()`
Clears the stack by deleting all nodes and freeing memory.

- **Operation**: Iterates over the stack and deletes each node.
- **Note**: After this change, the function does not return anything. It simply clears the stack, regardless of whether it was initially empty or not.

#### 10. `bool contains(T value) const`
Checks if a specific value is present in the stack.

- **Parameters**: `value` - The value to search for in the stack.
- **Throws**: `underflow_error` if the stack is empty.
- **Returns**: `true` if the value is found, `false` otherwise.

#### 11. `void reverse()`
Reverses the order of elements in the stack.

- **Throws**: `underflow_error` if the stack is empty.
- **Operation**: Iterates through the stack and reverses the links between nodes.

#### 12. `void display() const`
Displays the elements of the stack in the order from top to bottom.

- **Operation**: Iterates through the stack and prints the values.

#### 13. `Stack<T> clone()`
Creates and returns a new stack that is a clone of the current stack.

- **Returns**: A new `Stack` object containing the same elements as the current stack.

#### 14. `void swap(Stack<T> &s)`
Swaps the contents of the current stack with another stack.

- **Parameters**: `s` - The stack to swap with.
- **Operation**: Swaps the top pointers of the two stacks.

#### 15. `T* toArray() const`
Converts the stack to an array of type `T`.

- **Returns**: A pointer to a dynamically allocated array containing the elements of the stack.
- **Note**: When using `toArray()`, it is important to remember that the array is dynamically allocated, but it is the caller's responsibility to free the memory after usage.

## Example Usage

```cpp
#include "Stack_Linked_List.h"

int main() {
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the stack
    stack.display();  // Output: [ 30, 20, 10 ]

    // Pop an element and print it
    int poppedValue;
    stack.pop(poppedValue);
    cout << "Popped: " << poppedValue << endl;  // Output: Popped: 30

    // Peek the top element
    cout << "Top: " << stack.peek() << endl;  // Output: Top: 20

    // Clone the stack
    Stack<int> clonedStack = stack.clone();
    clonedStack.display();  // Output: [ 20, 10 ]

    // Reverse the stack
    stack.reverse();
    stack.display();  // Output: [ 10, 20 ]

    // Check if stack contains a value
    cout << "Contains 20: " << stack.contains(20) << endl;  // Output: Contains 20: 1 (true)

    return 0;
}

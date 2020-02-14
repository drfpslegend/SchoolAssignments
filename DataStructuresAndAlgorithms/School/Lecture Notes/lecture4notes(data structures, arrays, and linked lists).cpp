// Time complexity: O(1) = constant, O(n) = linear, 

// A data structure is a way to store and organize data in memory of a computer, in order to access and use it efficiently.
// We work with data structures such as mathematical/logical models or abstract data types.
// ex: List - stores a given number of elements of any type, accesses elements by position, modifies(edits) elements by position.
// Examples include arrays, linked lists, stacks, queues, trees, graphs, etc.
// Things to keep in mind: operations, logical view, cost of operations, implementation

// Array:  a group of contiguous memory locations under the same name and data type.
// Unused bytes = numberOfBytesPerElement * (totalElements - usedElements).
// Memory may not be available for large enough arrays as total memory may be currently used in chunks.
// Once declared, it has a fixed size and cannot be modified.
// If we need a larger array to add more elements, we need to declare a larger array and copy the elements of the smaller array into the larger array.
// array[i] = &array + numberOfBytesPerElement * i.
// Easy to implement, but has more memory limitations.
// Cost of reaching element n: O(1).
// Cost of inserting at the beginning: O(n).
// Cost of inserting at the end: O(1), O(n) if already full.
// Cost of inserting at i: O(n).
// Cost of deleting an element: O(n).

// Linked List: a dynamically allocated container structure.
// A node of a linked list is a block of memory that has data and a pointer to another node.
// The start of the list is called the head pointer, which points to the first element of the list.  It holds the address of the first element.
// The end of the list is the last node, which has a pointer that points to 0, NULL, or nullptr.
// Total memory needed for each node = numBytesForData + numBytesForPointer.
// No unused memory, but extra memory is needed for the pointer variable
// Size of a linked list is variable, so we do not need to declare different linked lists to increase size.
// Harder to implement, but has less memory limitations.
// Has possibility for memory leak (using up all the available memory) or segmentation fault (when a program wants to access a memory location that is off-limits, like writing to a read-only location).
// Cost of reaching element n: O(n).
// Cost of inserting at the beginning: O(1).
// Cost of inserting at the end: O(n).
// Cost of inserting at i: O(n).
// Cost of deleting an element: O(n).

// ex: Write a program for a a big company that can store information regarding salaries of its employees.
// What happens when hiring or firing someone?
// 1: using array...
// 	- indicate entries to change.
// 	- create new array.
// 2: using linked list...
// 	- indicate entries to change.
// 	- traverse list once per addition/deletion.

// ex: history of web browsers, human brain, word documents
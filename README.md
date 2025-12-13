# DSA1

This repository contains implementations of various Data Structures and Algorithms (DSA) concepts in C++. It serves as a learning resource for understanding fundamental DSA topics through code examples.

## Repository Structure

The repository is organized into the following main directories:

- **book/**: Basic OOP concepts and pointers in C++

  - `inheritance.cpp`: Demonstrates inheritance
  - `opp1.cpp`: Object-oriented programming basics
  - `pointers.cpp` to `pointers5.cpp`: Pointer manipulations and examples
  - `polym.cpp`: Polymorphism examples
  - `vector.cpp`: Vector usage

- **DSA_course/**: Core DSA implementations

  - **BST/**: Binary Search Tree
    - `binarySearchTree1.cpp`: BST implementation
    - `main1.cpp`, `main2.cpp`: Example usages
  - **Graph/**: Graph algorithms
    - `main1.cpp`: Graph implementation
  - **Hash Tables/**: Hash table examples
    - `main1.cpp`, `main2.cpp`: Hash table implementations
  - **Heaps/**: Heap data structure
    - `main1.cpp`, `main2.cpp`: Heap examples
  - **Linked list/**: Linked list implementations
    - `DLL.cpp`: Doubly Linked List
    - `LL1.cpp`: Singly Linked List
  - **List/**: List data structure
    - `main1.cpp`: List examples
  - **Pair/**: Pair usage
    - `main1.cpp`: Pair examples
  - **Priority Queue/**: Priority queue implementations
    - `priority_queue1.cpp`: Priority queue
  - **Queue/**: Queue data structures
    - `queue_built_In.cpp`: Built-in queue
    - `queue_vector1.cpp`, `queue_vector2.cpp`: Vector-based queues
    - `queue.cpp`: Custom queue
  - **Recursion/**: Recursive algorithms
    - `CallStack.cpp`: Call stack demonstration
    - `Factorial.cpp`: Factorial calculation
  - **Stack/**: Stack implementations
    - `minStack.cpp`: Minimum stack
    - `stack_built_In.cpp`: Built-in stack
    - `stack_vector1.cpp`: Vector-based stack
    - `stack.cpp`: Custom stack
  - **Unordered Map/**: Unordered map examples
    - `unordered_map1.cpp`: Unordered map usage

- **Maximum Product Difference Between Two Pairs/**: LeetCode-style problem

  - `main.cpp`: Solution implementation

- **Next Greater Element I/**: LeetCode-style problem

  - `main.cpp`: Solution implementation

- **test.cpp**: General test file

## Prerequisites

- C++ compiler (e.g., g++ on macOS/Linux, or Visual Studio on Windows)
- Basic knowledge of C++ programming

## Compilation and Execution

To compile and run any C++ file in this repository:

1. Open a terminal in the project directory.
2. Compile the file using g++:

   ```
   g++ filename.cpp -o output_name
   ```

   Replace `filename.cpp` with the actual file name (e.g., `g++ test.cpp -o test`).

3. Run the executable:
   ```
   ./output_name
   ```

For example, to run the test file:

```
g++ test.cpp -o test
./test
```

Note: Some files may require input or have specific dependencies. Check the code comments for details.

## Topics Covered

This repository covers a wide range of DSA topics including:

- Basic C++ concepts (OOP, pointers, vectors)
- Data Structures: Arrays, Linked Lists, Stacks, Queues, Trees, Graphs, Hash Tables, Heaps
- Algorithms: Recursion, Searching, Sorting (implied in implementations)
- Problem-solving: LeetCode-style challenges

## Contributing

Feel free to contribute by adding more implementations, fixing bugs, or improving documentation.

## License

This project is for educational purposes. Please refer to individual file headers for any specific licensing information.

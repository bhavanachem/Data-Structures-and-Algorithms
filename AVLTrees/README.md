# AVL Tree Implementation

This project implements an AVL tree using custom `BookNode` objects. The program reads book records from an input text file and constructs an AVL tree. It ensures the tree remains balanced by performing the necessary rotations when imbalances are detected.

## Features
- **Balanced Binary Search Tree**: Maintains AVL balance conditions.
- **Automatic Rotations**: Handles Left, Right, Left-Right, and Right-Left rotations to restore balance.
- **Book Management**: Reads `ISBN`, `Title`, and `Author` data from a file and creates `BookNode` objects.
- **Traversal**: Supports in-order traversal of the AVL tree for sorted output.
- **Visualization**: Prints the structure of the AVL tree, including balance factors and heights.

## Program Workflow
1. **Input**: The program reads book data (ISBN, Title, Author) from a file.
2. **Processing**:
   - Constructs an AVL tree by inserting nodes based on ISBN as the key.
   - Detects and corrects imbalances with appropriate rotations.
3. **Output**:
   - Displays the tree structure with node details.
   - Outputs the in-order traversal of the AVL tree.
   - Logs each imbalance and the rotation performed to resolve it.

## Files
- `Homework4_AVLTree.java`: The main program file containing the AVL tree implementation.
- `booklist.txt`: Input file containing book records.

---


## How It Works
- **BookNode Class**: Represents a book with `ISBN`, `title`, and `author`.
- **TreeNode Class**: Represents a node in the AVL tree, containing a `BookNode`, left and right child pointers, height, and balance factor.
- **AVLTree Class**: Manages the AVL tree operations:
  - **Insertion**: Inserts nodes based on ISBN, ensuring balance.
  - **Rotations**: Applies rotations to maintain AVL properties:
    - **Left Rotation**
    - **Right Rotation**
    - **Left-Right Rotation**
    - **Right-Left Rotation**
  - **Traversal**: Supports in-order traversal for sorted output.
  - **Visualization**: Prints the tree structure with balance factors.

<img width="1245" alt="HW4_AVLTreesOutput_1" src="https://github.com/user-attachments/assets/ca9a5f4a-135d-415b-adee-e44873c79ad3" />


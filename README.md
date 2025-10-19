# Binary Tree Remove Example

This folder contains a simple Binary Search Tree Remove implementation

## Files

- `tree_remove_example.cpp` - TODO: Implement the recursive `Remove` function
- `tree_remove_example_answer.cpp` - Complete solution
- `Makefile` - Build configuration for easy compilation
- `.vscode/` - VS Code debugging configuration

## Usage

### Compilation
```bash
make
```

### Running
```bash
./tree_remove_example
```

### Debugging in VS Code

1. Open the `tree_remove` folder in VS Code
2. Set breakpoints in the code by clicking in the left margin
3. Press F5 or go to Run → Start Debugging
4. The debugger will build and run the program

## Function
The `Remove(TreeNode* root, int value)` function removes a value from a binary search tree (BST) using recursion.

### Step-by-Step Implementation Instructions

1. **Base Cases**:  
   - If the current node (`root`) is `nullptr`, the value doesn't exist; return `nullptr`.
   - If the current node's value (`root->data`) equals the value to remove, handle the deletion based on the number of children. **Deletion Cases**:
      - **No children (leaf)**: Delete the node and return `nullptr`.
      - **One child**: Replace the node with its only child and delete the original node.
      - **Two children**: Find the minimum in right subtree, replace the current node's data with the minimum's data, then recursively remove the minimum from the right subtree.

3. **Recursive Case**:  
   - If the value to remove is **less than** the current node's value, recursively remove from the **left** subtree.
   - If the value to remove is **greater than** the current node's value, recursively remove from the **right** subtree.
   - Assign the result of the recursive call back to the appropriate child pointer.

4. **Return the (possibly updated) root**

## Example

The program starts with this binary search tree:
```
       4
      / \
     2   6
    / \ / \
   1  3 5  7
```

### Expected Output
```
Inorder Traversal:
=============================
1 2 3 4 5 6 7
Inorder Traversal after removing 2:
=============================
1 3 4 5 6 7
```

### Example Trace: Removing value 2 (has two children)

```
Remove(4, 2):
├─ 2 < 4, so go left
├─ Remove(2, 2):
│  ├─ Found target! Node has two children
│  ├─ Find minimum in right subtree: 3
│  ├─ Replace 2 with 3
│  ├─ Remove(3, 3): delete the original 3 node
│  └─ Assign updated subtree to original 2 node's right child
├─ Assign updated subtree to 4's left child
└─ Return root (4)
```

## Memory Management

The program includes a recursive `Clear` function that properly deallocates all memory:
- Traverses the entire tree recursively
- Deletes nodes in post-order (children first, then parent)
- Prevents memory leaks

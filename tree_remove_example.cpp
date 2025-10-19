#include <iostream>
#include <vector>

struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  
  // Constructor
  TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Inorder traversal function (recursive)
void Traversal(TreeNode* node) {
  if (node == nullptr) return;
  
  Traversal(node->left);
  std::cout << node->data << " ";
  Traversal(node->right);
}

// Clear function (recursive)
void Clear(TreeNode* root) {
  if (root == nullptr) return;
  Clear(root->left);
  Clear(root->right);
  delete root;
}

// Remove function (recursive)
TreeNode* Remove(TreeNode* root, const int& value) {
  // TODO: implement the function to remove value from the tree whose root is root
}

int main() {
  // Build a binary tree manually
  //       4
  //      / \
  //     2   6
  //    / \ / \
  //   1  3 5  7
  
  TreeNode* root = new TreeNode(4);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node6 = new TreeNode(6);
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node7 = new TreeNode(7);
  
  // Connect the nodes
  root->left = node2;
  root->right = node6;
  node2->left = node1;
  node2->right = node3;
  node6->left = node5;
  node6->right = node7;
  
  std::cout << "Inorder Traversal:" << std::endl;
  std::cout << "=============================" << std::endl;
  
  Traversal(root);
  std::cout << std::endl;

  // Remove the node with value 2
  root = Remove(root, 2);
  std::cout << "Inorder Traversal after removing 2:" << std::endl;
  std::cout << "=============================" << std::endl;
  Traversal(root);
  std::cout << std::endl;
  
  // Clean up memory
  Clear(root);
  
  return 0;
}

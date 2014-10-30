#include<iostream>
#include<string>
#include<vector>
#include<stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct Node {
  char flag; // 0: initial state, 1: left tree is visied, 2: right tree is visied.
  TreeNode *ptr;
  Node(char flag, TreeNode *ptr) : ptr(ptr), flag(flag) {}
  Node(const Node &n) {ptr = n.ptr; flag = n.flag;}
};


void postorderTraversal(TreeNode *root, std::vector<int> &result) {
  
  std::stack<struct Node> stack_; 
  struct Node node(0, root);
  stack_.push(node);

  while(!stack_.empty()) {
    struct Node node(stack_.top());
    stack_.pop();
    if (node.ptr != NULL) {
      if (node.flag == 2) {
        result.push_back(node.ptr->val);
      } else if (node.flag == 1) {
        node.flag = 2;
        stack_.push(node);
        struct Node p(0, node.ptr->right);
        stack_.push(p);
      } else {
        node.flag = 1;
        stack_.push(node);
        struct Node p(0, node.ptr->left);
        stack_.push(p);
      }
   }
 }
}


int main() {
  TreeNode *r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  std::vector<int> t;
  postorderTraversal(r, t);
  for (size_t i = 0; i < t.size(); i++) {
    std::cout << t[i] << std::endl;
  }
}

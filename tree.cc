#include <cassert>
#include <print>
#include <vector>

static int nodes_allocated = 0;

class Node {
public:
  Node *left;
  Node *right;
  int data;

  Node(int data, Node *left = nullptr, Node *right = nullptr)
      : left(left), right(right), data(data) {
    nodes_allocated++;
  }

  ~Node() { nodes_allocated--; }
};

class BinaryTree {
public:
  Node *root;

  BinaryTree() { root = nullptr; }

  std::vector<int> preorder() {
    // TODO: Implement preorder traversal
    std::vector<int> result;
    return result;
  }

  std::vector<int> inorder() {
    // TODO: Implement inorder traversal
    std::vector<int> result;
    return result;
  }

  std::vector<int> postorder() {
    // TODO: Implement postorder traversal
    std::vector<int> result;
    return result;
  }

  ~BinaryTree() {
    // TODO: Deallocate all nodes
  }
};

int main() {
  {
    {
      BinaryTree bt;
      assert(bt.preorder() == std::vector<int>({}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(1);
      assert(bt.preorder() == std::vector<int>({1}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(2, new Node(1), new Node(3));
      assert(bt.preorder() == std::vector<int>({2, 1, 3}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3));
      assert(bt.preorder() == std::vector<int>({1, 2, 4, 5, 3}));
    }
    std::println("preorder tests passed");
  }

  {
    {
      BinaryTree bt;
      assert(bt.inorder() == std::vector<int>({}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(1);
      assert(bt.inorder() == std::vector<int>({1}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(2, new Node(1), new Node(3));
      assert(bt.inorder() == std::vector<int>({1, 2, 3}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3));
      assert(bt.inorder() == std::vector<int>({4, 2, 5, 1, 3}));
    }
    std::println("inorder tests passed");
  }

  {
    {
      BinaryTree bt;
      assert(bt.postorder() == std::vector<int>({}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(1);
      assert(bt.postorder() == std::vector<int>({1}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(2, new Node(1), new Node(3));
      assert(bt.postorder() == std::vector<int>({1, 3, 2}));
    }
    {
      BinaryTree bt;
      bt.root = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3));
      assert(bt.postorder() == std::vector<int>({4, 5, 2, 3, 1}));
    }
    std::println("postorder tests passed");
  }

  assert(nodes_allocated == 0);
  std::println("Destructor test passed");

  std::println("All tests passed");

  return 0;
}

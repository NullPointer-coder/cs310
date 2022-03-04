#ifndef BECK_AVL
#define BECK_AVL
#include <cassert>
#include <iostream>

/**
 * An AVL tree class
 * NOT guaranteeed to work with duplicate elements
 * @author Jingbo Wang
 * @date Mar 22 2022
 */
template <typename Comparable>
class AVLTree
{
 public:
  /**
   * The default constructor for an empty tree
   */
  AVLTree() : root(nullptr) {}

  /**
   * The copy constructor
   * @param rhs the tree to be copied
   */
  AVLTree(const AVLTree& rhs) : root(rhs.clone(rhs.root))
  { }

  /**
   * The destructor deallocates all allocated memory
   */
  ~AVLTree()
  {
    make_empty();
  }

  /**
   * The standard operator=
   * @param rhs the tree to be copied
   * @return a clone of the parameter tree
   */
  const AVLTree& operator= (const AVLTree& rhs)
  {
    if (this != &rhs)
    {
      make_empty();
      root = rhs.clone(rhs.root);
    }
    return *this;
  }

  /**
   * Does an element with this data occur in the tree?
   * @param data the key to search for
   * @return whether or not the data is found
   */
  bool find(const Comparable& data) const
  {
    return find(data, root);
  }

  /**
   * Simple accessor to determine whether the tree is empty
   * @return whether or not the tree is empty
   */
  bool is_empty() const
  {
    return root == nullptr;
  }

  /**
   * A helper function for debugging.  Print the tree graphically,
   * sideways.
   */
  void print_tree() const
  {
    print_tree(root, 0);
  }

  /**
   * A simple accessor to report on the height of the tree.
   * @return 0 = an empty tree, 1 = a one-node tree, 2 = a tree
   * with two or three nodes, etc.
   */
  unsigned height() const
  {
    return height(root);
  }

  /**
   * Zero out and re-initialize an existing tree
   */
  void make_empty()
  {
    make_empty(root);
  }

  /**
   * Add a new element into the tree
   * @param data the data the new element is to contain
   */
  void insert(const Comparable& data)
  {
    insert(data, root);
  }

 private:

  struct AVL_node
  {
    Comparable data;
    unsigned height;
    AVL_node* left;
    AVL_node* right;

    AVL_node(const Comparable& data_p,
             AVL_node* left_p,
             AVL_node* right_p,
             unsigned height_p = 0)
      : data(data_p), height(height_p), left(left_p), right(right_p)
    {}
  };

  AVL_node* root;

  /**
   * Insert an element into a subtree
   * @param data is the item to insert.
   * @param t the node that roots the subtree.
   */
  void insert(const Comparable& data, AVL_node*& t)
  {
    if (t == nullptr)
    {
      t = new AVL_node(data, nullptr, nullptr);
    }
    else if (data < t->data)
    {
      insert(data, t->left);
      if (height(t->left) - height(t->right) == 2)
      {
        if (data < t->left->data)
        {
          rotateLL(t);
        }
        else
        {
          rotateLR(t);
        }
      }
    }
    else if (t->data < data)
    {
      insert(data, t->right);
      if (height(t->right) - height(t->left) == 2)
      {
        if (t->right->data < data)
        {
          rotateRR(t);
        }
        else
        {
          rotateRL(t);
        }
      }
    }
    // else duplicate; do nothing
    t->height = std::max(height(t->left), height(t->right)) + 1;
  }


  /**
   * Does an element with this data occur in this subtree?
   * @param data the key to search for
   * @param t the root of the subtree to search
   * @return whether or not the data is found
   */
  bool find(const Comparable& data, AVL_node* t) const
  {
    if (t == nullptr)
    {
      return false;
    }
    if (t->data == data)
    {
      return true;
    }
    if (t->data < data)
    {
      return find(data, t->right);
    }
    return find(data, t->left);
  }

  /**
   * Accessor to report on the height of the subtree
   * @param t the root of the subtree
   * @return 0 = an empty tree, 1 = a one-node tree, 2 = a tree
   * with two or three nodes, etc.
   */
  unsigned height(AVL_node* t) const
  {
    return t == nullptr ? 0 : t->height;
  }

  /**
   * Print a subtree, at level depth, sideways
   * Uses spaces per level to indicate the depth "graphically"
   * @param t the subtree to print
   * @param depth the depth of this node
   */
  void print_tree(AVL_node* t, unsigned int depth) const
  {
    const std::string LEVEL_SPACE = "     ";
    if (t != nullptr)
    {
      print_tree(t->right, depth + 1);
      for (unsigned i = 0; i < depth; i++)
      {
        std::cout << "     ";
      }
      std::cout << LEVEL_SPACE << t->data << std::endl;
      print_tree(t->left, depth + 1);
    }
  }

  /**
   * Zero out and re-initialize a subtree
   * @param t the root of the subtree
   */
  void make_empty(AVL_node*& t)
  {
    if (t != nullptr)
    {
      make_empty(t->left);
      make_empty(t->right);
      delete t;
      t = nullptr;
    }
  }

  /**
   * Make a deep copy of a subtree
   * @param t the subtree to clone
   * @return a pointer to the cloned subtree
   */
  AVL_node* clone(AVL_node* t) const
  {
    if (t == nullptr)
    {
      return nullptr;
    }
    return new AVL_node(t->data, clone(t->left), clone(t->right), t->height);
  }

  /**
   * Perform an RR rotation on a node
   * @param p the node on which to rotate
   */
  void rotateRR(AVL_node*& p)
  {
    AVL_node* orig_right = p->right;
    p->right = orig_right->left;
    orig_right->left = p;
    p->height = std::max(height(p->right), height(p->left)) + 1;
    orig_right->height = std::max(height(orig_right->right), p->height) + 1;
    p = orig_right;
  }

  void rotateLL(AVL_node*& p)
  {
  }

  void rotateLR(AVL_node*& p)
  {
  }

  void rotateRL(AVL_node*& p)
  {
  }
};

#endif

#include <bits/stdc++.h>
using namespace std;

// Structure for a node
struct node
{
  int data;
  struct node *left, *right;
  node(int x)
  {
    data = x;
    left = right = NULL;
  }
};

// Program to find kth ancestor
bool ancestor(struct node *root, int item, int &k)
{
  if (root == NULL)
    return false;

  // Element whose ancestor is to be searched
  if (root->data == item)
  {
    //reduce count by 1
    k = k - 1;
    return true;
  }
  else
  {

    // Checking in left side
    bool flag = ancestor(root->left, item, k);
    if (flag)
    {
      if (k == 0)
      {

        // If count = 0 i.e. element is found
        cout << "[" << root->data << "] ";
        return false;
      }

      // if count !=0 i.e. this is not the
      // ancestor we are searching for
      // so decrement count
      k = k - 1;
      return true;
    }

    // Similarly Checking in right side
    bool flag2 = ancestor(root->right, item, k);
    if (flag2)
    {
      if (k == 0)
      {
        cout << "[" << root->data << "] ";
        return false;
      }
      k = k - 1;
      return true;
    }
  }
}

// Driver Code
int main()
{
  struct node *root = new node(1);
  root->left = new node(4);
  root->left->right = new node(7);
  root->left->left = new node(3);
  root->left->right->left = new node(8);
  root->right = new node(2);
  root->right->right = new node(6);

  int item, k;
  item = 3;
  k = 1;
  int loc = k;
  bool flag = ancestor(root, item, k);
  if (flag)
    cout << "Ancestor doesn't exist\n";
  else
    cout << "is the " << loc << "th ancestor of [" << item << "]" << endl;
  return 0;
}

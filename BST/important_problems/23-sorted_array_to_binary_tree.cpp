/*Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.


*/

node* helper(vector<int>&num, int low, int high){
  if(low>high) return null;

  int mid = low + (high-low)/2;

  node* root  = num[mid];
  root->left = helper(num, low, mid-1);
  root->right = helper(num, mid+1, high);
  return root;
}

node* sortedArrayToBST(vector<int>&num){
  if(num.size() == 0) return nullptr;

  return helper(num, 0, num.size() - 1);
}


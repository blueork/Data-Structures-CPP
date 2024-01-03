#include <iostream>
using namespace std;

// Implementation of Node for the AVL Tree ADT
class AVLNode {
public:
	int data, height;
	AVLNode* left, * right;
	AVLNode( int data = 0, AVLNode* left = NULL, AVLNode* right = NULL, int height = 0) {
		this->data = data;
		this->left = left;
		this->right = right;
		this->height = height;
	}
	~AVLNode() {
		this->left = NULL;
		this->right = NULL;
	}
};

// Implementation of the AVL Tree ADT
class AVLTree {
private:
	AVLNode* root;
	void insert(AVLNode*& current, int& data) {
		if (current == NULL)			
			return;
		else if (current->data == data)			// if value already exists then ignore
			return;
		else if (data < current->data) {		// if value is less than the current value
			if (current->left == NULL)
				current->left = new AVLNode(data);		// if left child is empty 
			else
				this->insert(current->left, data);		// if left child is non-empty
		}
		else {															// if value is greater than the current value
			if (current->right == NULL)			
				current->right = new AVLNode(data);	// if right child is empty
			else
				this->insert(current->right, data);	// if right child is non-empty
		}
		current->height = findNodeHeight(current);
		this->rebalancing(current);
	}
	void LLrotation(AVLNode*& current) {
		if (current == NULL)
			return;
		AVLNode* left = current->left;
		current->left = left->right;
		left->right = current;
		current = left;
		current->right->height = this->findNodeHeight(current->right);
		current->height = this->findNodeHeight(current);
	}
	void RRrotation(AVLNode*& root) {
		if (root == NULL)
			return;
		AVLNode* rcRoot = root->right; // right child of root
		root->right = rcRoot->left;		// assigning left child of 
		// rcRoot as the right child
		// of root
		rcRoot->left = root;						// assigning root as the left child
		// of rcRoot
		root = rcRoot;											// updating root
		root->left->height = this->findNodeHeight(root->left);
		// updating height of left child
		// of new root after rotation
		root->height = this->findNodeHeight(root);
		// updating height of the new root
		// after rotation
	}
	void LRrotation(AVLNode*& root) {
		if (this->root == NULL)
			return;
		AVLNode* rightLC = root->left->right;
		// right child of the left child of the given root
		root->left->right = rightLC->left;
		// assigning the left child of rightLC as the right child
		// of the left Child of the given root
		rightLC->left = root->left;
		// assigning left Child of the given root as the left child
		// of the rightLC
		root->left = rightLC;
		// assigning rightLC as the new left child of the given root
		root->left->left->height = this->findNodeHeight(root->left->left);
		// updating the height of the left child of the left child of the given
		// root after the rotation
		root->left->height = this->findNodeHeight(root->left);
		// updating the height of the left child of the given root
		//  after the rotation
		this->LLrotation(root);
		// performing LL rotation on the resultant sub-tree
	}
	void RLrotation(AVLNode*& root) {
		if (this->root == NULL)
			return;
		AVLNode* leftRC = root->right->left;
		// left child of the right child of the given root
		root->right->left = leftRC->right;
		// assigning the right child of leftRC as the left child
		// of the right child of the given root
		leftRC->right = root->right;
		// assigning the right child of the given root as the right child
		// of the leftRC
		root->right = leftRC;
		// assigning leftRC as the new right child of the given root
		root->right->right->height = this->findNodeHeight(root->right->right);
		// updating the height of the new right child of the right child of the 
		// given root after the rotation
		root->right->height = this->findNodeHeight(root->right);
		// updating the height of the new right child of the given root
		// after the rotation
		this->RRrotation(root);
		// performing LL rotation on the resultant sub-tree
	}
	void inorder(AVLNode* current) {
		if (current == NULL)
			return;
		inorder(current->left);
		cout << current->data << " ";
		inorder(current->right);
	}
	void preorder(AVLNode* current) {
		if (current == NULL)
			return;
		cout << current->data;
		preorder(current->left);
		preorder(current->right);
	}
	void postorder(AVLNode* current) {
		if (current == NULL)
			return;
		postorder(current->left);
		postorder(current->right);
		cout << current->data;
	}
	void remove(AVLNode*& current, int& data) {
		if (current == NULL)
			return;
		if (current->data == data) {
			int degree = this->degree(current);
			if (degree == 0) {
				delete current;
				current = NULL;
			}
			else if (degree == 1) {
				AVLNode* temp = current;
				if (current->left == NULL)
					current = current->right;
				else
					current = current->left;
				delete temp;
				temp = NULL;
			}
			else {
				AVLNode* temp = current;
				current = findMinNode(current->right);
				current->left = temp->left;
				current->right = temp->right;
				delete temp;
				temp = NULL;
			}
		}
		if (current->data < data)
			this->remove(current->right, data);
		else
			this->remove(current->left, data);
		current->height = findNodeHeight(current);
		this->rebalancing(current);

 	}
	AVLNode* findMinNode(AVLNode*& current) { // finds the node with the minimum value in the given sub-tree
		AVLNode* temp = NULL;										// further replaces the node with its right child or NULL and	
		if (current->left == NULL) {				// returns it
			temp = current;	
			current = current->right;				// if min node is found
		}																				// replace it with right child or null
		else {
			temp = findMinNode(current->left);			// goin towards the left child
			current->height = this->findNodeHeight(current);		// update the height after the min node has been found
			this->rebalancing(current);									// rebalance the tree after the min node has been removed
		}
		return temp;		
	}
	int findMinValue(AVLNode*& current) {
		if (current == NULL)
			return -1;
		else if (current->left == NULL)
			return current->data;
		return findMinValue(current->left);
	}
	int findMaxValue(AVLNode*& current) {
		if (current == NULL)
			return -1;
		else if (current->right == NULL)
			return current->data;
		return findMaxValue(current->right);
	}
public:
	AVLTree(AVLNode* root = NULL) {
		this->root = root;
	}
	~AVLTree() {
		this->root = NULL;
	}
	void insert(int data) {
		if (this->root == NULL)
			this->root = new AVLNode(data);
		this->insert(root, data);
	}
	int findNodeHeight(AVLNode*& current) {
		if (current == NULL)
			return -1;
		int leftHeight = -1, rightHeight = -1;
		if (current->left)								// if left child exists
			leftHeight = current->left->height;	// find the height of the left child subtree
		if (current->right)							// if right child exists
			rightHeight = current->right->height;// find the height of the right child subtree
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		// returns the height of the subtree with greater height
	}
	int balanceFactor(AVLNode* current) {
		if (current == NULL)
			return -1;
		int leftHeight = -1, rightHeight = -1;
		if (current->left)
			leftHeight = current->left->height;
		if (current->right)
			rightHeight = current->right->height;
		return leftHeight - rightHeight;
	}
	int getBalanceFactor(AVLNode* root) {
		return balanceFactor(root);
	}
	void rebalancing(AVLNode*& current) {
		if (this->balanceFactor(current) == 2 && this->balanceFactor(current->left) == 1)
			this->LLrotation(current);
		else if (this->balanceFactor(current) == -2 && this->balanceFactor(current->right) == -1)
			this->RRrotation(current);
		else if (this->balanceFactor(current) == 2 && this->balanceFactor(current->left) == -1)
			this->LRrotation(current);
		else if (this->balanceFactor(current) == -2 && this->balanceFactor(current->right) == 1)
			this->RLrotation(current);
	}
	void display() {
		cout << "In-order traversal: ";
		this->inorder(root);
		cout << "\n";
	}
	void inOrderDisplay() {
		this->display();
	}
	void preOrderDisplay() {
		cout << "Pre-order traversal: ";
		this->preorder(root);
		cout << "\n";
	}
	void postOrderDisplay() {
		cout << "Post-order traversal: ";
		this->postorder(root);
		cout << "\n";
	}
	void remove(int data) {
		if (this->root == NULL)
			return;
		else
			this->remove(this->root, data);
	}
	int degree(AVLNode*& current) {
		if (current == NULL)		
			return -1;
		else if (current->right == NULL && current->left == NULL)	// if it has no child
			return 0;
		else if (current->right == NULL) // if it has one child
			return 1;
		else if (current->left == NULL)	// if it has one child
			return 1;
		else				// if it has two childs
			return 2;
	}
	int findMinValue() {
		if (this->root == NULL)
			return -1;
		this->findMinValue(this->root);
	}
	int findMaxValue() {
		if (this->root == NULL)
			return -1;
		this->findMaxValue(this->root);
	}
	bool verifyAVLTree(AVLNode*& root) {
		if (root == NULL)
			return true;
		if (verifyAVLTree(root->left) == false)
			return false;
		if (verifyAVLTree(root->right) == false)
			return false;
		root->height = this->findNodeHeight(root);
		int val = this->balanceFactor(root);
		if (val == -1 || val == 0 || val == 1)
			return true;
		else
			return false;
	}
	void splitTree(int threshold, AVLTree& treeA, AVLTree& treeB) {
		if (this->root == NULL)
			return;
		inorderValuesInsert(threshold, treeA, treeB, this->root);
	}
	// traverses the tree in inorder manner and copies the values into
	// treeA and treeB according to the threshold
	void inorderValuesInsert(int& threshold, AVLTree& treeA, AVLTree& treeB, AVLNode*& current) {
		if (current == NULL)
			return;
		inorderValuesInsert(threshold, treeA, treeB, current->left);
		if (current->data <= threshold)
			treeA.insert(current->data);
		else
			treeB.insert(current->data);
		inorderValuesInsert(threshold, treeA, treeB, current->right);
	}
	AVLNode* getRoot() {
		return this->root;
	}
};

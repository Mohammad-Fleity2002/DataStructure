#include"BST.h"

TreeNode* insert(TreeNode* h, int d) {//No Reprtition
	TreeNode* tmp = new TreeNode;
	if (h == NULL) {
		tmp->data = d;
		tmp->left = tmp->right = NULL;
		return tmp;
	}
	if (d < h->data) {
		h->left = insert(h->left, d);
	}
	else if (d > h->data) {
		h->right = insert(h->right, d);
	}
	return h;
}
TreeNode* initialize() {
	return NULL;
}
TreeNode* findMin(TreeNode* h) {
	if (h->left == NULL) {
		return h;
	}
	return findMin(h->left);
}
TreeNode* findMax(TreeNode* h) {
	if (h->right == NULL) {
		return h;
	}
	return findMax(h->right);
}
TreeNode* deleteNode(TreeNode* h, int d) {
	if (h == NULL) {
		return NULL;
	}
	if (h->data > d) {
		h->left = deleteNode(h->left, d);
	}
	else if (h->data < d) {
		h->right = deleteNode(h->right, d);
	}
	else {
		//Element found
		TreeNode* del, * tmp = new TreeNode;
		if (h->left != NULL && h->right != NULL) {
			tmp = findMin(h->right);
			h->data = tmp->data;
			deleteNode(h->right, tmp->data);
		}
		else {
			del = h;
			if (h->left != NULL) {
				h = h->left;
			}
			else {
				h = h->right;
			}
			delete del;
		}
	}
	return h;
}
bool isBST (TreeNode* h, TreeNode* max, TreeNode* min) {
	if (h == NULL) {
		return true;
	}
	if (h->data > max->data||h->data<min->data) {
		return false;
	}
	return isBST(h->left, h, min) && isBST(h->right, max, h);
}
int  nbOfNode1(TreeNode* h) {
	if (h == NULL) {
		return 0;
	}
	return nbOfNode1(h->left) + nbOfNode1(h->right) + 1;
}
void nbOfNode2(TreeNode* h, int& nn) {
	if (h == NULL) {
		return;
	}
	nn++;
	nbOfNode2(h->left,nn);
	nbOfNode2(h->right, nn);
}
int heightOfTree(TreeNode* h) {
	if (h == NULL) {
		return 0;
	}
	int left = heightOfTree(h->left);
	int right = heightOfTree(h->right);
	if (left > right) {
		return left + 1;
	}
	return right + 1;
}
int nbOfLeaves(TreeNode* h) {
	if (h == NULL) {
		return 0;
	}
	if (h->left == NULL && h->right == NULL) {
		return 1;
	}
	return nbOfLeaves(h->left) + nbOfLeaves(h->right);
}
int NbOfNodeWith2sibilings(TreeNode* h) {
	if (h == NULL) {
		return 0;
	}
	if (h->left != NULL && h->right != NULL) {
		return NbOfNodeWith2sibilings(h->right) + NbOfNodeWith2sibilings(h->left) + 1;
	}
	return NbOfNodeWith2sibilings(h->right) + NbOfNodeWith2sibilings(h->left);
}
void insert_Iterative(TreeNode*& h, int d) {
	TreeNode* tmp, * prv=NULL;
	tmp = new TreeNode;
	tmp->data = d;
	tmp->left = tmp->right = NULL;
	if (h == NULL) {
		h = tmp;
		return;
	}
	for (TreeNode* t = h; t != NULL;) {
		prv = t;
		if (h->data >= d) {
			t = t->left;
		}
		else {
			t = t->right;
		}
	}
	if (prv->data < d) {
		prv->right = tmp;
	}
	else
	{
		prv->left = tmp;
	}
	return;
}
void prefixREC(TreeNode* h) {
	if (h == NULL) {
		return;
	}
	cout << h->data << " ";
	prefixREC(h->left);
	prefixREC(h->right);
}
void infixREC(TreeNode* h) {
	if (h == NULL) {
		return;
	}
	infixREC(h->left);
	cout << h->data << " ";
	infixREC(h->right);
}
void postfixREC(TreeNode* h) {
	if (h == NULL) {
		return;
	}
	postfixREC(h->left);
	postfixREC(h->right);
	cout << h->data << " ";
}
void prefixITER(TreeNode* h) {
	if (h == NULL) {
		cout << "Empty BST" << endl;
		return;
	}
	stack<TreeNode*> s;
	TreeNode* t = h;
	s.push(t);
	cout << t->data << " ";
	t = t->left;
	while (t != NULL || !s.empty()) {
		while (t != NULL) {
			s.push(t);
			cout << t->data<<" ";
			t = t->left;
		}
		t = s.top();
		s.pop();
		t = t->right;
	}
	cout << endl;
}
void infixITER(TreeNode* h) {
	if (h == NULL) {
		cout << "Empty BST" << endl;
		return;
	}
	stack<TreeNode*> s;
	TreeNode* t = h;
	s.push(t);
	t = t->left;
	while (t != NULL || !s.empty()) {
		while (t != NULL) {
			s.push(t);
			t = t->left;
		}
		t = s.top();
		cout << t->data<<" ";
		s.pop();
		t = t->right;
	}
	cout << endl;
}
void postfixITER(TreeNode* h) {
	if (h == NULL) {
		cout << "Empty BST" << endl;
		return;
	}
	stack<TreeNode*> s;
	TreeNode* t = h,*r=NULL;
	if (t->right != NULL) {
		s.push(t->right);
	}
	s.push(t);
	t = t->left;
	while (t != NULL || !s.empty()) {
		while (t != NULL) {
			if (t->right != NULL) {
				s.push(t->right);
			}
			s.push(t);
			t = t->left;
		}
		t = s.top();
		s.pop();
		r = s.top();
		if (t->right!=NULL && r== t->right) {
			r = s.top();
			s.pop();
			s.push(t);
			t = t->right;
		}
		else {
			cout << t->data << " ";
			t = NULL;
		}
	}
	cout << endl;
}
void displayByLevel1(TreeNode* h) {
	if (h == NULL) {
		cout << "Empty BST" << endl;
		return;
	}
	queue<TreeNode*>q;
	TreeNode* t;
	q.push(h);
	while (!q.empty()) {
		t = q.front();
		q.pop();
		if (t->left != NULL) {
			q.push(t->left);
		}
		if (t->right != NULL) {
			q.push(t->right);
		}
		cout << t->data << " ";
	}
	cout << endl;
}
void displayByLevel2(TreeNode*h) {
	if (h == NULL) {
		cout << "Empty BST." << endl;
		return;
	}
	queue<TreeNode*>q;
	TreeNode* t;
	int level = 0, nbOfNodeByLevel = 0;
	q.push(h);
	while (!q.empty()) {
		cout << "Level " << level << ": ";
		nbOfNodeByLevel = q.size();
		level++;
		for (int i = 0; i < nbOfNodeByLevel; i++) {
			t = q.front(); 
			q.pop();
			if (t->left != NULL) {
				q.push(t->left);
			}
			if (t->right != NULL) {
				q.push(t->right);
			}
			cout << t->data << " ";
		}
		cout << "." << endl;
	}
}
void displayByOrder(TreeNode* h) {
	prefixREC(h);
	cout << "." << endl;
}

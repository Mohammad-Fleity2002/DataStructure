#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};
TreeNode* insert(TreeNode*, int);
TreeNode* findMin(TreeNode*);
TreeNode* findMax(TreeNode*);
TreeNode* deleteNode(TreeNode*, int);
TreeNode* initialize();
bool isBST(TreeNode*, TreeNode*, TreeNode*);
int heightOfTree(TreeNode*);
int nbOfNode1(TreeNode*);
int nbOfLeaves(TreeNode*);
int NbOfNodeWith2sibilings(TreeNode*);
void insert_Iterative(TreeNode*&, int);
void nbOfNode2(TreeNode*, int&);
void prefixREC(TreeNode*);
void infixREC(TreeNode*);
void postfixREC(TreeNode*);
void prefixITER(TreeNode*);
void infixITER(TreeNode*);
void postfixITER(TreeNode*);
void displayByLevel1(TreeNode*);
void displayByLevel2(TreeNode*);
void displayByOrder(TreeNode*);

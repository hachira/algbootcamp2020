#include <stdio.h>
#include <string.h>

struct MyNode
{
	int data;
	struct MyNode *left, *right;
};

MyNode *addNode(MyNode *root, int data)
{
	if( root == NULL )
	{
		MyNode *node = new MyNode;
		node->data = data;
		node->left = node->right = NULL;
		return node;
	}
	if(data < root->data) root->left = addNode(root->left, data);
	else root->right = addNode(root->right, data);
	return root;
}

bool searchNode(MyNode *root, int data)
{
	if(root == NULL) return false;
	if(data == root->data) return true;
	if(data < root->data) return searchNode(root->left, data);
	return searchNode(root->right, data);
}

MyNode *removeNode(MyNode *root, int data)
{
	//	CASE 0 : 발견하지 못한 경우
	if(root == NULL) return NULL;
	if(data < root->data)
	{
		root->left=removeNode(root->left, data);
		return root;
	}
	if(data > root->data)
	{
		root->right=removeNode(root->right, data);
		return root;
	}
	//	CASE 1 : 자식이 하나도 없는 경우
	if(root->left == NULL && root->right == NULL) return NULL;
	//	CASE 1 : 자식이 하나인 경우
	if(root->left == NULL) return root->right;
	if(root->right == NULL) return root->left;
	//	CASE 2 : 자식이 둘인 경우
	//	1. 오른쪽 서브트리중 가장 왼쪽의 노드를 찾는다.
	MyNode *tmp = root->right, *p = NULL;
	while(tmp->left != NULL) { p = tmp; tmp = tmp->left; }
	//	2. 찾은 경우 tmp 가장 왼쪽의 노드, p 그 부모
	root->data = tmp->data;
	if(p == NULL) root->right = tmp->right;
	else p->left = tmp->right;
	return root;
}

void print(MyNode *root)
{
	if(root == NULL) return;
	print(root->left);
	printf("[%d]", root->data);
	print(root->right);
}
//	이진검색트리를 만든다
//	a <number> 형태면 <number>를 검색트리에 추가한다
//	s <number> 형태면 <number>를 검색트리에서 찾는다.  있으면 true, 없으면 false
//	d <number> 형태면 <number>가 들어있는 노드를 삭제한다.
//	q 를 치면 종료
int main()
{
	MyNode *root = NULL;
	while(1)
	{
		int data;
		char cmd[16];
		scanf("%s", cmd);
		if(!strcmp(cmd, "q")) break;
		scanf("%d", &data);
		if(cmd[0]=='a') root=addNode(root, data);
		else if(cmd[0]=='s') puts(searchNode(root, data)?"true":"false");
		else if(cmd[0]=='d') root=removeNode(root, data);
	}
}

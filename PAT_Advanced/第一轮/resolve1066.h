#include "common.h"
namespace resolve1066 {
	int resolve();
	typedef struct tree_node
	{
		int key;
		int lh;
		int rh;
		struct tree_node* left;
		struct tree_node* right;
		struct tree_node* parent;
		tree_node(){
			key=0;
			lh=0;
			rh=0;
			left=nullptr;
			right=nullptr;
			parent=nullptr;
		};
		tree_node(int k,struct tree_node* p){
			key=k;
			lh=0;
			rh=0;
			left=nullptr;
			right=nullptr;
			parent=p;
		};
	}node;
	int get_height(node* root);
	/*
		����
	*/
	void l(node* n);
	/*
		����
	*/
	void r(node* n);
	/*
		����
	*/
	void lr(node* n);
	/*
		����
	*/
	void rl(node* n);
	/*
		���벢����ʧ��Ľڵ㣬���򷵻�nullptr
	*/
	void insert(node* head,int key);
}
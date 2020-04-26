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
		左旋
	*/
	void l(node* n);
	/*
		右旋
	*/
	void r(node* n);
	/*
		左右
	*/
	void lr(node* n);
	/*
		右左
	*/
	void rl(node* n);
	/*
		插入并返回失衡的节点，无则返回nullptr
	*/
	void insert(node* head,int key);
}
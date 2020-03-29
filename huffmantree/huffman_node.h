#ifndef __HUFFMAN_TREE_NODE_H__
#define __HUFFMAN_TREE_NODE_H__

// ¹þ·òÂüÊ÷½áµãÀà
struct HuffmanTreeNode
{
	int weight;
    int parent, leftchild, rightchild,id;
	HuffmanTreeNode();
	HuffmanTreeNode(int w, int p = 0, int lchild = 0, int rchild = 0,int ID=0):weight(w),parent(p),leftchild(lchild),rightchild(rchild),id(ID){};
    bool operator < (const HuffmanTreeNode &rhs)const{return weight>rhs.weight;}
};

HuffmanTreeNode::HuffmanTreeNode()
{
	parent = leftchild = rightchild = id=-1;
}


#endif


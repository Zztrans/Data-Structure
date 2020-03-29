#ifndef __HUFFMAN_TREE_H_
#define __HUFFMAN_TREE_H

#include "huffman_node.h"
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class huffmantree
{
protected:
    HuffmanTreeNode *nodes;
    char *leaf;
    string *leafcode;
    int num;
    void createhuffman(char ch[],int w[],int n);

public:
    huffmantree(char ch[],int w[],int n);
    ~huffmantree();
    string encode(char ch); //得到ch的编码
    string decode(string &t); //给编码解码

    int getnum() {return num;};
    void display(){for(int i=0;i<num;++i) cout<<"字符 "<<leaf[i]<<" 的编码为: "<<leafcode[i]<<endl;}
};



void huffmantree::createhuffman(char ch[],int w[],int n)
{
    num=n;
    int m=2*n-1;
    nodes=new HuffmanTreeNode [m];
    leaf=new char[n];
    leafcode=new string[n];
    int p,q;
    priority_queue<HuffmanTreeNode>pq;
    for(int i=0;i<n;++i)
    {
        nodes[i].weight=w[i];
        nodes[i].leftchild=-1;
        nodes[i].rightchild=-1;
        nodes[i].parent=-1;
        nodes[i].id=i;
        pq.push(nodes[i]);
        leaf[i]=ch[i];
    }
    for(int i=n;i<m;++i)
    {
        int r1=pq.top().id;
        pq.pop();
        int r2=pq.top().id;
        pq.pop();
        nodes[r1].parent=nodes[r2].parent=i;
        nodes[i].leftchild=r1;
        nodes[i].rightchild=r2;
        nodes[i].parent=-1;
        nodes[i].id=i;
        nodes[i].weight=nodes[r1].weight+nodes[r2].weight;
        pq.push(nodes[i]);
    }
    for(int i=0;i<n;++i)
    {
        string tmp="";
        q=i;
        p=nodes[q].parent;
        while(p!=-1)
        {
            if(nodes[p].leftchild==q) tmp+='0';
            else tmp+='1';
            q=p;
            p=nodes[q].parent;
        }
        reverse(tmp.begin(),tmp.end());
        leafcode[i]=tmp;
    }
}

huffmantree::huffmantree(char ch[],int w[],int n)
{
    createhuffman(ch,w,n);
}

huffmantree::~huffmantree()
{
    if(nodes!=NULL) delete []nodes;
    if(leaf!=NULL) delete []leaf;
    if(leafcode!=NULL) delete []leafcode;
}


string huffmantree::encode(char ch)
{
    for(int i=0;i<num;++i)
        if(leaf[i]==ch) return leafcode[i];
    return "error!";
}

string huffmantree::decode(string &t)
{
    string ans;
    int p=2*num-2;
    for(int i=0;i<t.size();++i)
    {
        if(t[i]=='0') p=nodes[p].leftchild;
        else p=nodes[p].rightchild;
        if(nodes[p].leftchild==-1 && nodes[p].rightchild==-1)
        {
            ans+=leaf[p];
            p=2*num-2;
        }
    }
    if(p!=2*num-2) return "error!";
    return ans;
}

#endif // HUFFMAN_TREE_H_

#ifndef __MIN_HEAP_H
#define __MIN_HEAP_H

#include <iostream>
using namespace std;

template<class type>
class MinHeap
{
protected:
    type *heaparr;
    int cursize;
    int maxsize;
public:
    MinHeap(int max_size);
    MinHeap(type a[],int n,int max_size);
	virtual ~MinHeap();
    void filterdown(int pos);
    void filterup(int pos);
    int parent(int pos) const;
    bool insert(const type &node);
    bool remove(int pos, type &node);
    type& removemin();
    int size()const {return cursize;};
	bool isempty() {return cursize==0;};
	void display();
};

template<class type>
MinHeap<type>::MinHeap(int max_size)
{
    if(maxsize<=0)
    {
        cout<<"堆的大小不能小于1"<<endl;
        exit(1);
    }
    maxsize=max_size;
    heaparr=new type[maxsize];
    cursize=0;
}

template<class type>
MinHeap<type>::MinHeap(type a[],int n,int max_size)
{
    if(n<=0)
    {
        cout<<"堆的大小不能小于1"<<endl;
        exit(1);
    }
    maxsize=max_size;
    heaparr=new type[max_size];
    heaparr=a;
    cursize=n;
    int i=(cursize-2)/2;  //最后一个二叉树 不符合就交换
    while(i>=0)
    {
        filterdown(i);
        i--;
    }
}

template<class type>
MinHeap<type>::~MinHeap()
{
    if(heaparr!=NULL)
        delete heaparr;
    maxsize=cursize=0;
}

template<class type>
void MinHeap<type>::filterdown(int pos)
{
    int i=pos;
    int j=2*i+1;
    type tmp=heaparr[i];
    while(j<cursize)
    {
        if( (j<cursize-1) && heaparr[j]>heaparr[j+1])
            j++;
        if(tmp<=heaparr[j]) break;
        else
        {
            heaparr[i]=heaparr[j];
            i=j;
            j=2*j+1;
        }
    }
    heaparr[i]=tmp;
}

template<class type>
void MinHeap<type>::filterup(int pos)
{
    int i=pos;
    type tmp=heaparr[i];
    while(i>0 && heaparr[parent(i)]>tmp)
    {
        heaparr[i]=heaparr[parent(i)];
        i=parent(i);
    }
    heaparr[i]=tmp;
}
template<class type>
int MinHeap<type>::parent(int pos) const
{
    if(pos && cursize>0) return (pos-1)/2;
    return 0;
}

template<class type>
bool MinHeap<type>::remove(int pos,type& node) //一般是堆顶 删除 用最后一元素顶替 然后向下或者向上调整
{
    if(pos>=cursize || pos<0) return false;
    type tmp=heaparr[pos];
    heaparr[pos]=heaparr[--cursize];
    if(heaparr[parent(pos)]>heaparr[pos]) filterup(pos);
    else filterdown(pos);
    node=tmp;
    return true;
}

template<class type>
bool MinHeap<type>::insert(const type& node)
{
    if(cursize==maxsize) return false;
    heaparr[cursize]=node;
    filterup(cursize);
    cursize++;
    return true;
}


template<class type>
type& MinHeap<type>::removemin()
{
    type tmp=NULL;
    if(cursize>0) remove(0,tmp);
    return tmp;
}

template<class type>
void MinHeap<type>::display()
{
    for(int i=0;i<cursize;++i)
        cout<<heaparr[i]<<' ';
    cout<<endl;
}

#endif // __MIN_HEAP_H

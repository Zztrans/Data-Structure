#include <iostream>
#include "Min_heap.h"

using namespace std;
int main()
{
    int a[]={5,4,3,8,7};
    cout<< "由序列 ";
    for(int i=0;i<5;++i) cout<<a[i]<<' ';
    cout<<"构造而成的最小堆 "<<endl<<"maxsize取20"<<endl;
    MinHeap<int> heap(a,5,20);
    char c='x';
	system("PAUSE");

   	while (c != '0'){
        cout << endl << "1. 显示堆.";
        cout << endl << "2. 删除堆顶.";
        cout << endl << "3. 插入元素.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	heap.display();
			    break;
           	case '2':
            	cout << endl << "输出删除堆顶元素的值:";
                cout<<heap.removemin();
			    break;
	         case '3':
				cout << endl << "输入插入元素的值:";
				int t;
				cin>>t;
				heap.insert(t);
				break;
	         case '0':
				break;
		}
   	}
    system("pause");
}

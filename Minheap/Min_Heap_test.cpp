#include <iostream>
#include "Min_heap.h"

using namespace std;
int main()
{
    int a[]={5,4,3,8,7};
    cout<< "������ ";
    for(int i=0;i<5;++i) cout<<a[i]<<' ';
    cout<<"������ɵ���С�� "<<endl<<"maxsizeȡ20"<<endl;
    MinHeap<int> heap(a,5,20);
    char c='x';
	system("PAUSE");

   	while (c != '0'){
        cout << endl << "1. ��ʾ��.";
        cout << endl << "2. ɾ���Ѷ�.";
        cout << endl << "3. ����Ԫ��.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~3):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	heap.display();
			    break;
           	case '2':
            	cout << endl << "���ɾ���Ѷ�Ԫ�ص�ֵ:";
                cout<<heap.removemin();
			    break;
	         case '3':
				cout << endl << "�������Ԫ�ص�ֵ:";
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

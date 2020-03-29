#include <iostream>
#include <string>
#include "huffman_tree.h"

using namespace std;

/* �������� ����  BDCAD   10011101011
                  DDBACD  1111100010111
            ����  10011101011    BDCAD
                  1111100010111  DDBACD

*/

int main()
{
	char s[]={"ABCD"};
	int w[]={12,3,5,9};
	huffmantree tree(s,w,4);
	tree.display();

    char c='x';
	system("PAUSE");
   	while (c != '0'){
        cout << endl << "1. ����encode.";
        cout << endl << "2. ����decode.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~2):";
		cin >> c;
        string tmp,ans;
        bool ok=1;
		switch (c) 	{
		    case '1':
		        cout<< endl << "��������ַ���:";
		        cin>>tmp;
		        ok=1;
		        for(int i=0;i<tmp.size();++i)
                {
                    string t=tree.encode(tmp[i]);
                    if(t=="error!")
                    {
                        cout<<"����Υ���ַ�!"<<endl;
                        ok=0;
                        break;
                    }
                    else ans+=t;
                }
                if(ok) cout<<endl<<"������:"<<ans<<endl;
			    break;
           	case '2':
            	cout << endl << "��������ַ���:";
            	cin>>tmp;
            	ans=tree.decode(tmp);
            	if(ans=="error!") cout<<endl<<"��������!"<<endl;
            	else cout<<endl<<"������:"<<ans<<endl;
			    break;
	         case '0':
				break;
		}
   	}
    system("pause");
}


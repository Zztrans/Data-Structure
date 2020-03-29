#include <iostream>
#include <string>
#include "huffman_tree.h"

using namespace std;

/* 测试数据 编码  BDCAD   10011101011
                  DDBACD  1111100010111
            解码  10011101011    BDCAD
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
        cout << endl << "1. 编码encode.";
        cout << endl << "2. 解码decode.";
		cout << endl << "0. 退出";
		cout << endl << "选择功能(0~2):";
		cin >> c;
        string tmp,ans;
        bool ok=1;
		switch (c) 	{
		    case '1':
		        cout<< endl << "输入编码字符串:";
		        cin>>tmp;
		        ok=1;
		        for(int i=0;i<tmp.size();++i)
                {
                    string t=tree.encode(tmp[i]);
                    if(t=="error!")
                    {
                        cout<<"存在违法字符!"<<endl;
                        ok=0;
                        break;
                    }
                    else ans+=t;
                }
                if(ok) cout<<endl<<"编码结果:"<<ans<<endl;
			    break;
           	case '2':
            	cout << endl << "输入解码字符串:";
            	cin>>tmp;
            	ans=tree.decode(tmp);
            	if(ans=="error!") cout<<endl<<"编码有误!"<<endl;
            	else cout<<endl<<"解码结果:"<<ans<<endl;
			    break;
	         case '0':
				break;
		}
   	}
    system("pause");
}


#include<bits/stdc++.h>
#include"slist.cpp"
using namespace std;
class qlns
{
	private :
		 string macanbo;
		 string hoten;
		 string phongban;
		 string chucvu;
		 int hesoluong;
	public :
	qlns()
	{
		
	}
	friend istream &operator>>(istream &is,qlns &ql)
	{
	
		cout<<"nhap ma can bo :";getline(is,ql.macanbo);
		cout<<"nhap ho va ten :";getline(is,ql.hoten);
		cout<<"nhap phong ban :";getline(is,ql.phongban);
		cout<<"nhap chuc vu :";getline(is,ql.chucvu);
		cout<<"nhap he so luong :";is>>ql.hesoluong;
		cin.ignore();
		return is;
	}
	friend ostream &operator<<(ostream &os,qlns ql)
	{
		os<<ql.macanbo<<" "<<ql.hoten<<" "<<ql.phongban<<" "<<ql.chucvu<<" "<<ql.hesoluong<<endl;
		return os;
    }
    string getChucvu()
    {
    	return chucvu;
	}
};	
int main()
{
   qlns ql;
   slist<qlns> L;
   cin>>ql;
   L.push_front(ql);
   cout<<"\nDanh sach quan ly nhan su vua nhap la:\n";
   for(slist<qlns>::iterator x=L.begin();x!=L.end();x++) cout<<*x;
   string tenchucvu;
   cout<<"nhap ten chuc vu can tim :";
   getline(cin,tenchucvu);
    for(slist<qlns>::iterator x=L.begin();x!=L.end();x++)
   if(x*.Search(tenchucvu))
		cout << "Tim thay";
	else
		cout << "Ko co";
}


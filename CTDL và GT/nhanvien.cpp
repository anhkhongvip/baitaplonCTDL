#include <bits/stdc++.h>
#include"slist.cpp"
using namespace std;
class qlns{
	public:
		int manv;
		string hoten;
		string	phongban;
		string chucvu;
		float hsluong;
		qlns(){
			manv=0;
			hsluong=0;
			hoten=phongban=chucvu="";
		}
		friend istream &operator>>(istream &is,qlns &ql)
		{
			cout<<"Ho ten: ";
			is.ignore();
			getline(is,ql.hoten);
			cout<<"Phong ban: ";
			getline(is,ql.phongban);
			cout<<"Chuc vu: ";
			getline(is,ql.chucvu);
			cout<<"He so luong: ";
			is>>ql.hsluong;
			return is;
		}
		friend ostream &operator<<(ostream &os,qlns ql)
		{
			os<<"\nMa nhan vien: "<<ql.manv;
			os<<"\nHo ten: "<<ql.hoten;
			os<<"\nPhong ban: "<<ql.phongban;
			os<<"\nChuc vu: "<<ql.chucvu;
			os<<"\nHe so luong: "<<ql.hsluong;
			return os;
		}
			
};

istream &operator>>(istream &is, slist<qlns> &nv) {
	qlns t;
	while(cout<<"Ma nhan vien: " && is>>t.manv && t.manv>0) {
		cin >> t;
		nv.push_back(t);
	}
	cout<<"Ket thuc nhap!\n";
	return is;
}

ostream &operator<<(ostream &out, slist<qlns> nv) {
	for(slist<qlns>::iterator it=nv.begin(); it!=nv.end(); it++) {
		cout << *it;
	}
}

void them(slist<qlns> &nv) {
	int vt;
	qlns t;
	cout<<"Nhap vi tri can them: ";
	cin>>vt;
	cout<<"Nhap thong tin nhan vien can them: ";
	cout<<"Ma nhan vien: ";
	cin >> t.manv >> t;
	slist<qlns>::iterator it=nv.begin();
	for(int i=0; i<vt; i++) it++;
	nv.insert(it, t);
}

void tinhluong(slist<qlns> nv) {
	for(slist<qlns>::iterator it=nv.begin(); it!=nv.end(); it++) {
		cout << (*it).hoten << ' ' << (int)((*it).hsluong*1350000) << '\n';
	}
}

void hesoluonglon(slist<qlns> nv) {
	for(slist<qlns>::iterator it=nv.begin(); it!=nv.end(); it++) {
		if((*it).hsluong>=4.4) {
			cout << *it;
		}
	}
}

void search_chucvu(slist<qlns> nv) {
	string s;
	cout << "\nNhap chuc vu can tim: ";
	cin.ignore();
	getline(cin, s);
	for(slist<qlns>::iterator it=nv.begin(); it!=nv.end(); it++) {
		if((*it).chucvu==s) {
			cout << *it;
		}
	}
} 

void search_hsluong_phongban(slist<qlns> nv) {
	string s;
	float t;
	cout << "\nNhap he so luong can tim: ";
	cin >> t;
	cout << "Nhap phong ban can tim: ";
	cin.ignore();
	getline(cin, s);
	for(slist<qlns>::iterator it=nv.begin(); it!=nv.end(); it++) {
		if((*it).phongban==s && (*it).hsluong==t) {
			cout << *it;
		}
	}
}

void sapxepnhanvien(slist<qlns> &nv) {
	for(slist<qlns>::iterator it=nv.begin(); it!=nv.end(); it++) {
		for(slist<qlns>::iterator j=nv.begin(); j!=nv.end(); j++) {
			if((*it).hoten>(*j).hoten) {
				qlns t = *it;
				*it = *j;
				*j = t;
			}
		}
	}
	cout<<"DS sau khi sap xep la:\n"<<nv;
}

int menu(){
	int chon;
	cout<<"\n\nHE THONG QUAN LY NHAN VIEN";
	cout<<"\n1. Hien thi DS nhan vien.";
	cout<<"\n2. Them NV vao vi tri tuy chon.";
	cout<<"\n3. Tinh luong nhan vien.";
	cout<<"\n4. Hien thi danh sach NV co luong >=4.4.";
	cout<<"\n5. Tim DS can bo theo chuc vu.";
	cout<<"\n6. Tim DS can bo theo he so luong va phong ban.";
	cout<<"\n7. Sap xep DS can bo theo thu tu cua ten.";
	cout<<"\n8. Thoat";
	cout<<"\nNhap lua chon: ";
	cin>>chon;
	return chon;
}

int main ()
{
	slist<qlns> nv; //danh sach nhan vien
	cout<<"Moi nhap danh sach nhan vien:\n";
	cin >> nv;
	while(true) {
		switch(menu()) {
		case 1:
			cout<<nv;
			break;	
		case 2:
			them(nv);
			break;
		case 3:
			tinhluong(nv);
			break;
		case 4:
			hesoluonglon(nv);
			break;
		case 5:
			search_chucvu(nv);
			break;
		case 6:
			search_hsluong_phongban(nv);
			break;
		case 7:
			sapxepnhanvien(nv);
			break;
		case 8:
			return 0;
		}
	}
}

//cai dat node
#include <bits/stdc++.h>
#ifndef __node__cpp__
#define __node__cpp__
using namespace std;
template<class T>
class node{
	private:
		T elem;//Gia tri cua node
		node<T> *next;//Chua dia chi node tiep theo
	public:
		node<T>(){next = NULL;}//Ham tao khong doi
		node<T>(T x,node<T> *N=0){//Ham tao co doi
			elem = x;
			next = N;
		}
		T &getElem(){ return elem;}
		void setElem(T x){ elem = x;}
		node<T> *&getNext(){return next;}
		void setNext(node<T> *N){ next = N;}
};
#endif
//int main(){
//	node<int> N;
//	N.getElem() = 2;
//	node<int> *A =  new node<int>(7,&N);
//	node<int> *B =  new node<int>(6);
//	N.setNext(B);
//	for(node<int> *p=A;p!=0;p=p->getNext()) cout<<p->getElem()<<" ";//Duyet
//}

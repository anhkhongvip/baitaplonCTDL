#include<bits/stdc++.h>
#ifndef __nodek__cpp__
#define __nodek__cpp__
using namespace std;
template<class T>
class node
{
	private :
		T elem;//gia tri cua node
		node<T> *next;//chua dia chi node tiep theo
	public :
		node<T>()
		{
			next=NULL;
		}//ham tao k doi
		node<T>(T x,node<T> *N=NULL)
		{
			elem=x;
			next=N;
		}
		T &getElem()
		{
			return elem;
		}
		void setElem(T x)
		{
			elem=x;
		}
		node<T> *&getNext()
		{
			return next;
		}
		void setNext(node<T> *N)
		{
			next=N;
		}
};
#endif
//int main()
//{
//node<int> N;
//
//N.getElem()=2;
//node<int> *A= new node<int>(7,&N);
//node<int> *B=new node<int>(6);
//N.setNext(B);
//
//for(node<int> *p=A; p!=NULL;p=p->getNext()) cout<<p->getElem()<<" ";
//}



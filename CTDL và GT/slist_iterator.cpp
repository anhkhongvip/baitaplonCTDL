#include <bits/stdc++.h>
#include"node.cpp"
#ifndef __slist_iterator__cpp
#define __slist_iterator__cpp
using namespace std;
template<class T>
class slist_iterator{
	node<T> *curr;
	public:
		slist_iterator(node<T> *c=0){curr=c;}
		node<T> *&getcurr(){return curr;}

		T &operator*(){
			 return curr->getElem();
		}
		bool operator!=(slist_iterator<T> it1){
			return curr!=it1.getcurr();
		}
		slist_iterator<T> operator++(int){//it++
			curr=curr->getNext();
			return curr;
		}
		slist_iterator<T> operator++(){//++it
			slist_iterator<T> it1 = curr;
			curr = curr->getNext();
			return it1;
		}
};
#endif
//int main(){
//	node<int> N;
//	N.getElem() = 2;
//	node<int> *A =  new node<int>(7,&N);
//	node<int> *B =  new node<int>(6);
//	N.setNext(B);
//	cout<<"\nDia chi con tro A: "<<A<<endl;
//	cout<<"\Gia tri elem cua A la: "<<A->getElem();
//	slist_iterator<int> it;//it(A)
//	cout<<"\nDia chi con tro curr cua it: "<<it.getcurr()<<endl;
//	it=A;
//	cout<<"\nDia chi con tro curr cua it sau khi gan: "<<it.getcurr()<<endl;
//	cout<<"\nGia tri elem ma con tro curr cua it dang tro: "<<it.getcurr()->getElem()<<endl;
////	slist_iterator<int> null(NULL);
//	for(;it!=NULL;++it) cout<<*it<<" ";//Duyet
//}


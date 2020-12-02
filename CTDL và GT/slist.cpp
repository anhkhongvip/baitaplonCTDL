#include <bits/stdc++.h>
#include"node.cpp"
#include"slist_iterator.cpp"
#ifndef __slist__cpp
#define __slist__cpp
using namespace std;
template<class T>
class slist{
	node<T> *head,*trail;
	int num;
	public:
		slist(){
			head=trail=nullptr;
			num=0;
		}
		slist(int k, T x){
			num=0;
			while(k--){
				push_back(x);
			}
		}
		node<T> *gethead(){	return head;}
		node<T> *gettrail(){return trail;}
		int size(){return num;}
		bool empty(){return num==0;}
		T &front(){return head->getElem();}
		T &back(){return trail->getElem();}
		void push_back(T x){
			//TH1: Neu danh sach chua co gi
			if(num==0){
				head=trail=new node<T>(x);
			}
			//TH 2: Neu danh sach da co
			else{
				trail->setNext(new node<T>(x));
				trail=trail->getNext();
			}
			num++;
		}
		void push_front(T x){
			//TH1: Neu danh sach chua co gi
			if(num==0) head=trail=new node<T>(x);
			else {
				head = new node<T>(x,head);
			}
			num++;
		}
		void pop_front(){
			if(num==0) return;
			if(num==1){
				head=trail=0;
			}else{
				head = head->getNext();
			}
			num--;
		}
		void pop_back(){
			if(num==0) return;
			if(num==1){
				head=trail=0;
			}else{
				node<T> *p=head;
				while(p->getNext()!=trail) p=p->getNext();
				p->setNext(0);
				trail=p;
			}
			num--;
		}
		//friend node<T> 
		bool Search(T x)
		{
		  	node<T> *pTmp=head;
		  	while(pTmp!=NULL)
		  	{
		  		if(pTmp->getElem() == x)
		  		  {
		  		  	return true; // neu tim thay index thì thoat khoi vong lap
		  		  }	
				  pTmp=pTmp->getNext();// chua tim thay thi tiep tuc duyet phan tu ke tiep
		  	}
			  return false;	
		}
				/* sap xep trong danh sách liên ket don theo theo thu tu tang dan */
		friend void SortList(slist &list)
		{
		  // for loop thu nhat
		 for(node<T> *pTmp=list.head;pTmp!=NULL;pTmp=pTmp->getNext())
		    {
		   //for loop thu hai
		     for(node<T> *pTmp2=pTmp->getNext();pTmp2!=NULL;pTmp2=pTmp2->getNext())
		        {
		         if(pTmp->getElem()<pTmp2->getElem()) // neu gia tri truoc > gia tri sau thì hoan doi hai vi tri
		           {
				       int tmp=pTmp->getElem();
				       pTmp->getElem()=pTmp2->getElem();
				       pTmp2->getElem()=tmp;
		           }
		    	}		
		 	}
		}
		typedef slist_iterator<T> iterator;
		iterator begin(){
			return head;
		}
		iterator end(){
			return NULL;
		}
		void insert(iterator it, T x){
			if(it.getcurr()==head) return push_front(x);//Neu bien lap dang o dau thi chen vao dau
			node<T> *p = head;//Tao 1 con tro chay tu head
			while(p->getNext()!=it.getcurr()) p=p->getNext();//Chay den khi nao dung truoc vi tri curr cua it dang tro den thi dung
			p->setNext(new node<T>(x,it.getcurr()));//Chen 1 node vao giua p va curr cua it
			num++;
		}
		void erase(iterator it){
			if(it.getcurr()==head) return pop_front();//Neu bien lap dang o dau thi goi pop_front()
			if(it.getcurr()==trail) return pop_back();
			node<T> *p = head;//Tao 1 con tro chay tu head
			while(p->getNext()!=it.getcurr()) p=p->getNext();//Chay den khi nao dung truoc vi tri curr cua it dang tro den thi dung
			p->setNext(it.getcurr()->getNext());//Chen 1 node vao giua p va curr cua it
			num--;
		}
};
#endif
//int main ()
//{
//slist<int> L;
//for(int i =1;i<=10;i++) L.push_back(i);
//slist<int>::iterator it=L.begin();
//
////L.insert(it,0);
////L.erase(it);
////node<int> *it = L.gethead();
////for(;it!=NULL;it=it->getNext()) cout<<it->getElem();
//for(slist<int>::iterator it=L.begin();it!=L.end();it++) 
//    
//	cout<<*it<<" ";
//
//cout<<endl;  
//int index;
//cout<<"nhap phan tu can tim kiem :";
//cin>>index;
//bool pFound = L.Search(index);
//  if(pFound == false){
//    cout<<"Khong tim thay so "<<index<<" trong danh sách"; 
//  }
//  else{
//    cout<<"Da tim thay so "<<index<<" trong danh sách.";
//  }
//
////Sap xep các phan tu trong danh sách
//  cout<<"\nDanh sach truoc khi sap xep la : ";
//  for(slist<int>::iterator it=L.begin();it!=L.end();it++) 
//     {
//	 cout<<*it<<" ";
//     }
//cout<<endl;
//  SortList(L);
//cout<<"\nDanh sach sau khi sap xep la : ";
//  for(slist<int>::iterator it=L.begin();it!=L.end();it++) 
//     {
//	 cout<<*it<<" ";
//     }  
//}    

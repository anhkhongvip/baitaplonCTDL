#include <bits/stdc++.h>
#include"node.cpp"
#include"slist_itearator.cpp"
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
			if(num==0)
			head=trail=new node<T>(x);
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
		
		typedef slist_iterator<T> iterator;
		iterator begin(){
			return head;
		}
		iterator end(){
			return NULL;
		}
		void insert(iterator it, T x)
		{
			if(it.getcurr()==head)
		    return push_front(x);//Neu bien lap dang o dau thi chen vao dau
			node<T> *p = head;//Tao 1 con tro chay tu head
			while(p->getNext()!=it.getcurr())
		    p=p->getNext();//Chay den khi nao dung truoc vi tri curr cua it dang tro den thi dung
			p->setNext(new node<T>(x,it.getcurr()));//Chen 1 node vao giua p va curr cua it
			num++;
		}
		void erase(iterator it){
			if(it.getcurr()==head)
			return pop_front();//Neu bien lap dang o dau thi goi pop_front()
			if(it.getcurr()==trail) 
			return pop_back();
			node<T> *p = head;//Tao 1 con tro chay tu head
			while(p->getNext()!=it.getcurr())
		    p=p->getNext();//Chay den khi nao dung truoc vi tri curr cua it dang tro den thi dung
			p->setNext(it.getcurr()->getNext());//Chen 1 node vao giua p va curr cua it
			num--;
		}
};
#endif
//int main ()
//{
//slist<int>L;
//for(int i =1;i<=10;i++) L.push_back(i);
//slist<int>::iterator it=L.begin();
//
//L.insert(it,0);
//L.erase(it);
////node<int> *it = L.gethead();
////for(;it!=NULL;it=it->getNext()) cout<<it->getElem();
//for(slist<int>::iterator it=L.begin();it!=L.end();it++) 
//cout<<*it;
//
//  return 0;
//}
//


#include <bits/stdc++.h>
using namespace std;
struct ListNode {
	int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x,int y) : key(x),val(y), next(NULL),prev(NULL) {}
 };
class LRUCache{
	int cc;
	int n;
	ListNode* head;
	ListNode* tail;
 	public:
 	LRUCache(int c){
 		n = 0;
 		cc = c;
 		head = NULL;
 		tail = NULL;
 	}
 	void insert(int key,int value){
 		ListNode* t = new ListNode(key,value);
 		if(head==NULL){
 			head = t;
 			tail = t;
 		}
 		else{
 			tail->next = t;
 			t->prev = tail;
 			tail = t;
 		}
 	}
 	void delete(int key){
 		ListNode* t = head;
 		ListNode* p = NULL;
 		while(t->key!=key){
 			p = t;
 			t = t>next;
 		}
 		if(p!=NULL){
 			p->next = t->next;
 			t->next->prev = p;
 		}
 		else{
 			head = head->next;
 			head->prev = NULL;
 		}
 	}
 	bool find(int key){
 		ListNode* t = head;
 		while(t!=NULL){
 			if(t->key==key) return true;
 			t = t->next;
 		}
 		return false;
 	}
 	int LRUCache::get(int key) {

	}
	
	void LRUCache::set(int key, int value) {
		
	}
 	
};
int main(){
	return 0;
}
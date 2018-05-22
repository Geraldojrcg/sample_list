#include <iostream>
namespace sc{
	template<typename T>
	class list{
		public:
			class node{
				public:
					node * next;
					T data;
					node(T val=0, node* nxt = nullptr) : data(val), next(nxt){};
			};
			list(){
				head = new node();
			};
			T front(){
				return head->next->data;
			}
			node * last(){
				auto aux = head->next;
				while(aux->next != nullptr){
					aux=aux->next;
				}
				return aux;
			}
			T back(){
				auto aux = last();
				return aux->data;
			}
			void print(){
				auto first = head->next;
				auto l = last();
				std::cout<<"[ ";
				while(first != l->next){
					std::cout<< first->data;
					std::cout<<" ";
					first = first->next;
				}
				std::cout<<"]\n";
			}
			void push_front(T data){
				auto target = new node(data, head->next);
				head->next = target; 
			}
			void push_back(T data){
				auto aux = last();
				auto target = new node(data, aux->next);
				aux->next = target;
			}
			void pop_front(){
				auto target = new node();
				target = head->next;
				head->next = target->next;
				delete target;
			}
			void pop_back(){
				auto aux = last();
				auto target = new node();
				target = head->next;
				while(target->next != aux){
					target = target->next;
				}
				delete aux;
				target->next = nullptr;
			}
		private:
			node * head;
	};	
}
int main(int argc, char const *argv[])
{
	sc::list<int> l{};
	l.push_front(1);
	l.push_back(1);
	l.push_back(3);
	l.pop_back();
	l.pop_front();
	l.print();
	//std::cout << l.back() << std::endl;
	return 0;
}

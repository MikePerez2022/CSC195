#pragma once

#include <initializer_list>
#include <limits>
#include <iostream>
namespace nc
{
	template<typename T>
	class list
	{
		struct node_t
		{
			node_t(const T& value) : _value{ value } {}
			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};

	public:
		list() { };

		list(const std::initializer_list<T>& ilist);

		list(const list& other); 

		~list();

		list& operator = (const list& other);
		T& front() { return _head->_value; }; 
		const T& front() const { return _head->_value; };
		T& back() { node_t* tail = this->tail(); return tail->_value; }; 
		const T& back() const { node_t* tail = this->tail(); return tail->_value; }; 
		void push_front(const T& value);
		void pop_front();
		void push_back(const T& value);
		void pop_back();		
		void remove(const T& value); 
		void reverse();
		
		//Not required ***************************************************
		//void resize(size_t count, const T& value = T{});  // use a loop if I do this for extra credit

		void clear() { _head = nullptr; }; 
		bool empty() { return (size() == 0); }
		size_t size();
		
		//Not Required ***************************************************
		//size_t max_size() { return std::numeric_limits<size_t>::max(); }
		
		std::ostream& write(std::ostream& stream);
	private:
		node_t* tail();
	private:
		node_t* _head{ nullptr };
	};

	/////////////////

	template<typename T>
	list<T>& list<T>::operator = (const list& other) {
		clear(); 
		node_t* oldN = other._head;
		
		while (oldN) {
			push_back(oldN->_value);
			oldN = oldN->_next;
		}


		return *this;
	}	

	/////////////////

	template<typename T>
	typename list<T>::node_t* list<T>::tail() {
		node_t* node = _head; 

		while (_head != nullptr) {
						
			if (node->_next != nullptr) {
				node = node->_next; 
			}
			else {
				return node;
			}
			
		}

		return node;
	}
	
	/////////////////

	template<typename T>
	list<T>::list(const std::initializer_list<T>& ilist) {

		
		node_t* tail = this->tail(); 


		for (auto iter = ilist.begin(); iter != ilist.end(); iter++) {
			
			node_t* node;

			node = new node_t(*iter);
			
			if (ilist.begin() == iter) {
				node->_next = nullptr;
				node->_prev = nullptr;
				_head = node;
				tail = node;
			} else {
				
				node->_next = nullptr;
				node->_prev = tail;
				tail->_next = node;
				tail = node;
			}
			
		}
						
	}

	/////////////////

	template<typename T>
	inline std::ostream& list<T>::write(std::ostream& stream){

		//node_t* node = new node_t(NULL); 

		node_t* node = _head; 
		while (node != nullptr) { 
			stream << node->_value << " "; 
			node = node->_next; 
		}

		stream << "\n";

		return stream; 
	}

	/////////////////

	template<typename T>
	inline void list<T>::push_back(const T& value){
		
		node_t* node = new node_t(value);
		node_t* tail = this->tail();

		node->_next = nullptr;
		node->_prev = tail;
		if (node->_prev == nullptr) {
			_head = node;
		}
		else {
			tail->_next = node;
		}
		tail = node;

	}

	/////////////////

	template<typename T>
	inline void list<T>::push_front(const T& value) {

		node_t* node = new node_t(value);
		node_t* prevHead = _head;

		if (node->_next == nullptr) {
			node_t* tail = this->tail();
			tail = node;
			
		}
		else {

			prevHead->_prev = node;
		}


		node->_next = prevHead;
		node->_prev = nullptr;
		
		_head = node;

	}

	/////////////////

	template<typename T>
	inline size_t list<T>::size(){

		node_t* node = _head;

		size_t count = 0;
		while (node) {
			node = node->_next;
			count++;
		}
		return count;
	}

	/////////////////

	template<typename T>
	list<T>::list(const list& other) {
		clear();
		node_t* node = other._head;
		node_t* bs = new node_t(NULL);

		bs->_value = node->_value;
		bs->_next = node->_next;
		bs->_prev = node->_prev;
		_head = bs;

	}
	
	/////////////////

	template<typename T>
	list<T>::~list() {
		node_t* node;

		while (_head != nullptr) {
			node = _head;
			_head = node->_next;
			delete node;
		}

		_head = nullptr;
	}

	/////////////////

	template<typename T>
	void list<T>::pop_front() {
		node_t* node = _head;
		node_t* nextHead = node->_next; 
		nextHead->_prev = nullptr;
		_head = nextHead;

		node->_next = nullptr;
		node->_prev = nullptr;
		delete node;
	}

	/////////////////

	template<typename T>
	void list<T>::pop_back() {
		node_t* tail = this->tail();

		node_t* delnode = tail;

		tail = delnode->_prev;
		tail->_next = nullptr;

		delnode->_prev = nullptr;
		delete delnode;

		//or
		//delnode->_prev = nullptr;
		//delnode->_value = NULL;
	}

	/////////////////

	template<typename T>
	void list<T>::remove(const T& value) {
		node_t* traverser = _head;
		node_t* delNode;
		node_t* nextNode;
		node_t* prevNode;

		while (traverser != nullptr) {
			if (traverser->_value == value) {
				nextNode = traverser->_next;
				prevNode = traverser->_prev;

				delNode = traverser;

				if (nextNode == nullptr) {
					pop_back();

					node_t* tail = this->tail();
					traverser = tail;

					traverser = traverser->_next;
				}
				else if (prevNode == nullptr) {
					pop_front();

					traverser = _head;
					traverser = traverser->_next;
				}
				else {
					nextNode->_prev = prevNode;
					prevNode->_next = nextNode;
					traverser = traverser->_next;
					delete delNode;
					
				}
					 
				//delete delNode;
				// or 
				//delNode->_value = NULL;
				//delNode->_next = nullptr;
				//delNode->_prev = nullptr;
			}
			else
			{
				traverser = traverser->_next;
			}
		}
	}

	/////////////////

	template<typename T>
	void list<T>::reverse() {
		node_t* node = _head;
		clear();

		clear(); 
		while (node)
		{
			push_front(node->_value);
			node = node->_next;
		}
	}


	// ********************** Doubly Linked List -- demo for understanding -- personal research

	/* -------------  
	template<typename T>
	void list<T>::fp() {

		node_t* head;
		node_t* tail;

		//add first node
		node_t* node = new node_t;

		node->_value = 1;
		node->_next = nullptr;
		node->_prev = nullptr;
		head = node; 
		tail = node; 

		//add second node
		node = new node_t;

		node->_value = 2;
		node->_next = nullptr;
		node->_prev = tail;
		tail->_next = node;
		tail = node;

		//add third node
		node = new node_t;

		node->_value = 3;
		node->_next = nullptr;
		node->_prev = tail;
		tail->_next = node;
		tail = node;

		//add final node
		node = new node_t;

		node->_value = 4;
		node->_next = nullptr;
		node->_prev = tail;
		tail->_next = node;
		tail = nullptr;

		printForward(head);

	}

	*/

	// ********************** Linked List -- demo for understanding -- personal research

	/*  
	template<typename T>
	void list<T>::fp() {
		node_t* n;
		node_t* t;
		node_t* h;

		n = new node_t; 
		t = new node_t; 
		h = new node_t; 

		n->_value = 1; 
		t = n;   
		h = n;  

		n = new node_t; 
		n->_value = 2; 

		t->_next = n;  
		t = t->_next; 

		n = new node_t;
		n->_value = 3;

		t->_next = n;
		t = t->_next;

		n = new node_t;
		n->_value = 4;

		t->_next = n;
		t = t->_next;

		n->_next = NULL;
	}
	*/	

}
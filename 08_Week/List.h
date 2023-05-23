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
			node_t* _next{ nullptr }; // if null = bottom
			node_t* _prev{ nullptr }; // if null = top
		};

	public:
		void fp();
		void printForward(node_t*head);

		list() { };

		list(const std::initializer_list<T>& ilist); // done?

		list(const list& other); //*** -- copy constructor
		//~list(); //***
		list& operator = (const list& other); // done
		//T& front(); //***
		//const T& front() const; //***
		//T& back(); //***
		//const T& back() const; //***
		void push_front(const T& value);
		//void pop_front(); //***
		void push_back(const T& value); // ???
		//void pop_back(); //***
		//void remove(const T& value); // find and remove //***
		//void reverse(); // see references for implementation //***
		
		//Not required ***************************************************
		//void resize(size_t count, const T& value = T{});  

		void clear() { _head = nullptr; }; // ???
		bool empty() { return (size() == 0); } // done
		size_t size(); // done
		
		//Not Required ***************************************************
		//size_t max_size() { return std::numeric_limits<size_t>::max(); }
		
		std::ostream& write(std::ostream& stream); // done?
	private:
		node_t* tail(); // done?
	private:
		node_t* _head{ nullptr }; // done?
	};


	//////////////////////////
	template<typename T>
	list<T>& list<T>::operator = (const list& other) {
		/*
		clear();
		node_t* node = other._head;	
		
		while (node) {
			push_back(node->_value);
			node = node->_next;
		}

		return *this;

		*/
		
		clear();
		node_t* oldN = other._head;
		//node_t* bs = new node_t(NULL);

		//bs->_value = node->_value;
		//bs->_next = node->_next;
		//bs->_prev = node->_prev;
		//_head = bs;

		
		
		while (oldN) {
			push_front(oldN->_value);
			
			oldN = oldN->_next;
		}

		//_head = oldN;

		return *this;
	}	

	/////////////////////     ---------------------        I think this is finished
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
	}
	


	/////////////////////     ----------------------       I think this is finished
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


	////////////////////     -----------------             I think this is finished
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

	///////////////////      -----------------             I think this is finished

	template<typename T>
	inline void list<T>::push_back(const T& value){
		
		node_t* node = new node_t(value);
		node_t* tail = this->tail();

		node->_next = nullptr;
		node->_prev = tail;
		tail->_next = node;
		tail = node;

	}

	///////////////////      -----------------             I think this is finished

	template<typename T>
	inline void list<T>::push_front(const T& value) {

		node_t* node = new node_t(value);
		node_t* prevHead = _head;

		prevHead->_prev = node;

		node->_next = prevHead;
		node->_prev = nullptr;
		_head = node;

	}

	//////////////////

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

	/////////////////          ------------------------    This isn't finished

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
	


	// ********************** print logic

	/*  ------------------   
	template<typename T>
	void list<T>::printForward(node_t*head) {
		node_t* traverser = head;
		while (traverser != nullptr){
			cout << traverser->_value << "\n";
			traverser = traverser->_next;
		}
	}
	*/

	// ********************** Doubly Linked List - it works without the constructor

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

	// ********************** Linked List - it works without the constructor

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
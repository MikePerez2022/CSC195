#pragma once
#include <initializer_list>
#include <limits>
namespace nc
{
	template<typename T>
	class vector
	{
	public:
		//Constructor
		vector();
		vector(size_t capacity);
		vector(const std::initializer_list<T>& ilist);
		vector(const vector& other);

		//Destructor
		~vector();

		//Operators
		vector& operator = (const vector& other) { return *this; };//currently nc::vector<int>

		T& operator [] (size_t position) { return _elements[position]; };
		const T& operator [] (size_t position) const { return _elements[position]; };

		//Methods
		T& at(size_t position) { return _elements[position]; }; //Later
		const T& at(size_t position) const { return _elements[position]; };
		T& front() { return _elements[0]; }; //First Record
		T& back() { return _elements[_size - 1]; }; //Last Record
		T* data() { return _elements; };
		void push_back(const T& value); //Add a Record and maybe increase capacity
		void pop_back() { if (_size > 0) --_size; };
		void reserve(size_t capacity); //Increase the size of the array
		void resize(size_t new_size, const T& value = T{});
		void clear() { _size = 0; }; //Set so no values are in the list
		void swap(vector& other);
		bool empty() const { return _size == 0; }; //Is the list empty
		size_t size() const { return _size; }; //Num of cells with data
		size_t capacity() const { return _capacity; };
		size_t max_size() const { return std::numeric_limits<size_t>::max() / sizeof(T); }

	private:
		//Properties
		T* _elements{ nullptr };
		size_t _size{};
		size_t _capacity{};
	};





//////////////////////////////////
	template<typename T>
	vector<T>::vector(){
		_capacity = 0;
		_size = 0;
	}

	/////////////////////
	template<typename T>
	vector<T>::vector(size_t capacity) {
		this->_capacity = capacity;
		_size = 0;
		_elements = new T[capacity];
	}

	// //////////////////////
	template<typename T>
	vector<T>::vector(const std::initializer_list<T>& ilist) {
		_size = ilist.size();
		_capacity = _size;
		_elements = new T[_capacity];

		//Copy all values to our array
		size_t count = 0; 
		for (auto iter = ilist.begin(); iter != ilist.end(); iter++) {
			_elements[count] = *iter; // Could also [count++]
			count++;
		}
	}

	// ///////////////////////////////
	template<typename T>
	vector<T>::vector(const vector& other) {
		_size = other.size();
		_capacity = other.capacity();
		_elements = new T[_capacity];

		for (size_t count = 0; count < _size; count++) {

			_elements[count] = other[count];// maybe other._elements[count]
		} 
	}
	//////////////

	


	template<typename T>
	void vector<T>::push_back(const T& value) {
		if (_size == _capacity) {
			reserve(_capacity + 5);

		}
		_elements[_size] = value;
		_size++;

	}

	///////////
	template<typename T>
	void vector<T>::reserve(size_t capacity) {
		if (capacity <= _capacity) return;

		T* new_elements = new T[capacity];
		//move data from old to new

		for (size_t count = 0; count < _size; count++) {
			new_elements[count] = _elements[count];
			
		}
		delete[] _elements;
		_elements = new_elements;
		_capacity = capacity;
	}

	//////////////////
	template<typename T>
	vector<T>::~vector() {
		_capacity = NULL;
		_size = NULL;

		delete[] _elements;
	}

	///////////////
	
	template<typename T>
	void vector<T>::swap(vector& other) {
		vector(other);
	}

	///////////////

	template<typename T>
	vector<T>& vector<T>::operator = (const vector& other) {
		clear();
		size_t* node = other._size;
		while (node) {
			push_back(node);
			node = none->_next;
		}

		return *this;
	}
	

	///////////////
	/*
	template<typename T>
	void vector<T>::resize(size_t new_size, const T& value = T{}) {
		
		T* new_elements = new T[new_size];

		if (new_size < _size) {
			for (size_t count = 0; count < new_size; count++) {
				new_elements[count] = _elements[count];
			}
		}
		else if (new_size > _size && value != NULL) {
			for (size_t count = 0; count < new_size; count++) {
				
				if (count > _size) {
					new_elements[count] = value;
				}
				else {
					new_elements[count] = _elements[count];
				}
			}
		}
		else if (new_size > _size) {
			for (size_t count = 0; count < new_size; count++) {

				if (count > _size) {
					break;
				}
				else {
					new_elements[count] = _elements[count];
				}
			}
		}
		
	}
	*/
	
	
}


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
		vector() {}
		vector(size_t capacity);
		vector(const std::initializer_list<T>& ilist);
		//vector(const vector& other);

		//Destructor
		//~vector();

		//Operators
		//vector& operator = (const vector& other);
		//T& operator [] (size_t position);
		//const T& operator [] (size_t position) const;

		//Methods
		//T& at(size_t position); //Later
		//const T& at(size_t position) const;
		T& front() { return _elements[0]; }; //First Record
		T& back() { return _elements[_size - 1]; }; //Last Record
		//T* data();
		//void push_back(const T& value); //Add a Record and maybe increase capacity
		void pop_back() { if (_size > 0) --_size; };
		//void reserve(size_t capacity); //Increase the size of the array
		//void resize(size_t new_size, const T& value = T{});
		void clear() { _size = 0; }; //Set so no values are in the list
		//void swap(vector& other);
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
	template<typename T>
	vector<T>::vector(size_t capacity) {
		this->_capacity = capacity;
		_size = 0;
		_elements = new T[capacity];
	}
	template<typename T>
	vector<T>::vector(const std::initializer_list<T>& ilist) {
		_size = ilist.size();
		_capacity = _size;
		_elements = new T[_capacity];

		//Copy all values to our array

		for (size_t iCount = 0; iCount < _size; iCount++) {
			_elements[iCount] = ilist[iCount]; //Might need to de-reference it
		}
	}
}


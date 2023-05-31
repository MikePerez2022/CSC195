#pragma once

#include <initializer_list>
#include <limits>
#include <iostream>

namespace hm
{
	template<typename T>
	class Hangman
	{
		struct word
		{
			word(const T& value) : data{ value } {}
			T data;
			word* next{ nullptr };
			word* prev{ nullptr };
		};

	public:
		Hangman() {};
		Hangman(const std::initializer_list<T>& ilist);
		Hangman(const Hangman& other);

		Hangman<T>& operator = (const Hangman& other);

		void printList();

		bool checkChar(char checker, const Hangman& other, bool check);
		bool checkWord(std::string checker);
		void hideWord(std::string checker);

		void push_front(const T& value);
		void pop_front();
		void push_back(const T& value);
		void pop_back();
		void clear() { head = nullptr; };

		void remove(const T& value);
		std::ostream& write(std::ostream& stream);
	private:
		word* tail();
	private:
		word* head{ nullptr };

	};



	template<typename T>
	Hangman<T>& Hangman<T>::operator = (const Hangman& other) {
		clear();
		word* oldN = other.head;

		while (oldN) {
			push_back(oldN->data);
			oldN = oldN->next;
		}


		return *this;
	}

	

	template<typename T>
	typename Hangman<T>::word* Hangman<T>::tail() {
		word* nodeH = head;

		while (head != nullptr) {

			if (nodeH->next != nullptr) {
				nodeH = nodeH->next;
			}
			else {
				return nodeH;
			}

		}

		return nodeH;
	}

	

	template<typename T>
	Hangman<T>::Hangman(const std::initializer_list<T>& ilist) {


		word* tail = this->tail();


		for (auto iter = ilist.begin(); iter != ilist.end(); iter++) {

			word* nodeN;

			nodeN = new word(*iter);

			if (ilist.begin() == iter) {
				nodeN->next = nullptr;
				nodeN->prev = nullptr;
				head = nodeN;
				tail = nodeN;
			}
			else {

				nodeN->next = nullptr;
				nodeN->prev = tail;
				tail->next = nodeN;
				tail = nodeN;
			}

		}

	}


	template<typename T>
	inline std::ostream& Hangman<T>::write(std::ostream& stream) {


		word* nodeN = head;
		while (nodeN != nullptr) {
			stream << nodeN->data << " ";
			nodeN = nodeN->next;
		}

		stream << "\n";

		return stream;
	}


	template<typename T>
	inline void Hangman<T>::push_back(const T& value) {

		word* nodeN = new word(value);
		word* tail = this->tail();

		nodeN->next = nullptr;
		nodeN->prev = tail;
		if (nodeN->prev == nullptr) {
			head = nodeN;
		}
		else {
			tail->next = nodeN;
		}
		tail = nodeN;

	}

	template<typename T>
	inline void Hangman<T>::push_front(const T& value) {

		word* nodeN = new word(value);
		word* prevHead = head;

		if (nodeN->next == nullptr) {
			word* tail = this->tail();
			tail = nodeN;

		}
		else {

			prevHead->prev = nodeN;
		}


		nodeN->next = prevHead;
		nodeN->prev = nullptr;

		head = nodeN;

	}


	template<typename T>
	Hangman<T>::Hangman(const Hangman& other) {
		clear();
		word* nodeN = other.head;
		word* nodeD = new word(NULL);

		nodeD->data = nodeN->data;
		nodeD->next = nodeN->next;
		nodeD->prev = nodeN->prev;
		head = nodeD;

	}


	template<typename T>
	void Hangman<T>::pop_front() {
		word* nodeN = head;
		word* nextHead = nodeN->next;
		nextHead->prev = nullptr;
		head = nextHead;

		nodeN->next = nullptr;
		nodeN->prev = nullptr;
		delete nodeN;
	}

	
	template<typename T>
	void Hangman<T>::pop_back() {
		word* tail = this->tail();

		word* delnode = tail;

		tail = delnode->prev;
		tail->next = nullptr;

		delnode->prev = nullptr;
		delete delnode;

	}

	
	template<typename T>
	void Hangman<T>::remove(const T& value) {
		word* traverser = head;
		word* delNode;
		word* nextNode;
		word* prevNode;

		while (traverser != nullptr) {
			if (traverser->data == value) {
				nextNode = traverser->next;
				prevNode = traverser->prev;

				delNode = traverser;

				if (nextNode == nullptr) {
					pop_back();

					word* tail = this->tail();
					traverser = tail;

					traverser = traverser->next;
				}
				else if (prevNode == nullptr) {
					pop_front();

					traverser = head;
					traverser = traverser->next;
				}
				else {
					nextNode->prev = prevNode;
					prevNode->next = nextNode;
					traverser = traverser->next;
					delete delNode;

				}

			}
			else
			{
				traverser = traverser->next;
			}
		}
	}


	template<typename T>
	inline void Hangman<T>::printList() {
		std::string printWord;

		word* nodeN = head;
		while (nodeN != nullptr) {
			printWord += nodeN->data;
			printWord += " ";
			nodeN = nodeN->next;
		}

		std::cout << printWord << "\n";
	}


	template<typename T>
	inline bool Hangman<T>::checkChar(char checker, const Hangman& other, bool check) {
		bool result = false;
		word* originTraverser = head;
		word* traverser = other.head;

		while (originTraverser != nullptr) {
			if (originTraverser->data == checker) {
				if (check) {
					traverser->data = checker;
					traverser = traverser->next;
				}
				originTraverser = originTraverser->next;
				result = true;
			}
			else
			{
				originTraverser = originTraverser->next;
				if (check) {
					traverser = traverser->next;
				}
			}
		}

		return result;
	}


	template<typename T>
	inline bool Hangman<T>::checkWord(std::string check) {

		std::string checker;
		word* traverser = head;

		while (traverser != nullptr) {
			checker += traverser->data;
			traverser = traverser->next;
		}

		if (checker._Equal(check)) {
			return true;
		}
		else {
			return false;
		}

	}


	template<typename T>
	inline void Hangman<T>::hideWord(std::string check) {

		if (checkWord(check)) {

			word* traverser = head;

			while (traverser != nullptr) {
				traverser->data = '_';
				traverser = traverser->next;
			}

		}
		else {
			std::cout << "How did this even happen?";
		}

	}

}
#pragma once

class List { //description of class for lists
private:
	void reset_list(); //function to clear and reset all list

	class Element //description of class for list's elements 
	{
	public:
		Element(int inf, Element* next = nullptr, Element* prev = nullptr) { //constructor of element's parameters
			this->information = inf;
			this->next = next;
			this->prev = prev;
		};
		~Element() {}; //destructor of element's parameters

		int information; //element's parameters
		Element* prev, * next; 
	};

	Element* head, * tail; //list's parameters
	size_t list_size;

public:
	List(); //list-constructor
	~List(); //list-destructor

	//list's methods
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void insert(int, size_t);
	int at(size_t);
	void remove(size_t);
	size_t get_size();
	void print_to_console();
	void clear();
	void set(size_t, int);
	bool isEmpty();

	void push_front(List);
};
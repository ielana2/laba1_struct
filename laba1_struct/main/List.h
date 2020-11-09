#pragma once

class List {
private:
	void reset_list();

	class Element
	{
	public:
		Element(int inf, Element* next = nullptr, Element* prev = nullptr) {
			this->information = inf;
			this->next = next;
			this->prev = prev;
		};
		~Element() {};

		int information;
		Element* prev, * next;
	};

	Element* head, * tail;
	size_t list_size;

public:
	List();
	~List();

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
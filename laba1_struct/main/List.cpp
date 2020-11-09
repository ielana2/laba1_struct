#include <iostream>
#include "List.h"
#include <stdexcept>

using namespace std;

void List::reset_list() {
	head = nullptr;
	tail = nullptr;
	list_size = 0;
}

List::List() {
	reset_list();
}

List::~List() {
	if (head) {
		while (head->next) {
			head = head->next;
			delete head->prev;
		}
		reset_list();
	}
}

void List::push_back(int inf) {
	Element* current = new Element(inf);
	current->next = nullptr;

	if (list_size == 0) {
		head = tail = current;
		current->prev = nullptr;
	}
	else {
		tail->next = current;
		current->prev = tail;
		tail = current;
	}
	list_size++;
}

void List::push_front(int inf) {
	Element* current = new Element(inf);
	current->prev = nullptr;
	if (list_size == 0) {
		head = tail = current;
		current->next = nullptr;
	}
	else {
		head->prev = current;
		current->next = head;
		head = current;
	}
	list_size++;
}

void List::pop_back() {
	if (list_size == 0)
		throw out_of_range("List is empty");

	if (list_size == 1) {
		delete head;
		reset_list();
	}
	else {
		Element* current = tail->prev;
		current->next = nullptr;
		delete tail;
		tail = current;
		list_size--;
	}
}

void List::pop_front() {
	if (list_size == 0)
		throw out_of_range("List is empty");

	if (list_size == 1) {
		delete head;
		reset_list();
	}
	else {
		Element* current = head->next;
		current->prev = nullptr;
		delete head;
		head = current;
		list_size--;
	}
}

void List::insert(int inf, size_t index) {
	if (index > list_size - 1)
		throw out_of_range("Index is greater than size of the list");

	if (index == 0)
		push_front(inf);

	else {
		Element* add_element = new Element(inf);
		Element* current = head;

		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}

		add_element->next = current->next;
		current->next->prev = add_element;
		add_element->prev = current;
		current->next = add_element;



		list_size++;
	}
}

int List::at(size_t index) {
	if (index > list_size - 1)
		throw out_of_range("Index is greater than size of the list");

	Element* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	return current->information;
}

void List::remove(size_t index) {
	if (index > list_size - 1)
		throw out_of_range("Index is greater than size of the list");

	if (index == 0)
		pop_front();

	else if (index == list_size - 1)
		pop_back();
	else {
		Element* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		list_size--;
	}
}

size_t List::get_size() {
	return list_size;
}

void List::print_to_console() {
	system("CLS");

	if (list_size == 0) {
		cout << "List is empty";
	}
	else {
		Element* current = head;
		for (int i = 0; i < list_size; i++) {
			cout << current->information << endl;
			current = current->next;
		}
	}

	system("pause");
}

void List::clear() {
	if (head) {
		head->next = head;
		delete head;
	}

	reset_list();
}

void List::set(size_t index, int change_inf) {
	if (index > list_size - 1)
		throw out_of_range("Index is greater than size of the list");

	Element* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	current->information = change_inf;
}

bool List::isEmpty() {
	if (list_size == 0)
		return true;
	else
		return false;
}

void List::push_front(List Another_List) {
	head->prev = Another_List.tail;
	Another_List.tail->next = head;
	head = Another_List.head;

	list_size += Another_List.get_size();
	Another_List.reset_list();
}
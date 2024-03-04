#include "queue.hpp"
#include <iostream>
#include <vector>

template<class T>
Queue<T>::Queue() : size(0) {}

template<class T>
Queue<T>::Queue(const Queue& other) : size(other.size), data(other.data) {}

template<class T>
Queue<T>::~Queue() {}

template<class T>
bool Queue<T>::empty() {
	if (size == 0) {
		return true;
	}

	return false;
}

template<class T>
void Queue<T>::push(T value) {
	size++;
	data.push_back(value);
}

template<class T>
T Queue<T>::pop() {
	size--;
	T top = data.back();
	data.pop_back();
	return top;
}

template<class T>
int Queue<T>::getSize() {
	return size;
}

template Queue<int>::Queue();
template Queue<int>::~Queue();
template bool Queue<int>::empty();
template void Queue<int>::push(int value);
template int Queue<int>::pop();
template int Queue<int>::getSize();
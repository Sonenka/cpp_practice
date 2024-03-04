#pragma once
#include <iostream>
#include <vector>

template<class T>
class Queue {
private:
	int size;
	std::vector<T> data;
public:
	Queue();
	Queue(const Queue& other);
	~Queue();

	bool empty();
	void push(T value);
	T pop();
	int getSize();
};
#include<iostream>
#include<array>
#include"Reference.h"
#include "ReferenceManager.h"

using namespace std;

ReferenceManager::ReferenceManager(int capacity) {
	array_capacity = capacity;
	reference_array = new Reference*[capacity];
}

ReferenceManager::~ReferenceManager() {

}

ReferenceManager::ReferenceManager(const ReferenceManager &other) {
	array_capacity = other.array_capacity;
	size_track = this->size_track;
	reference_array = other.reference_array;
}

bool ReferenceManager::addReference(Reference &reference) {
	if (size_track < array_capacity) {
		reference_array[size_track] = &reference;
		size_track++;
		return true;
	} else
		return false;
}

int ReferenceManager::getReference(int pos) {
	return reference_array[pos]->getReferenceId();
}

// Note that the deleteReference function does not call the destructor. It overwrites the element at index (pos) by the element at (pos + 1)
bool ReferenceManager::deleteReference(int pos) {
	if (pos < size_track) {
		size_track--;
		for (int count = pos; count < (size_track); count++) {
			reference_array[count] = reference_array[count + 1];
		}

		return true;
	} else
		return false;
}

bool ReferenceManager::searchReference(int id) {
	for (int count = 0; count < size_track; count++) {
		if (reference_array[count]->getReferenceId() == id)
			return true;
	}
	return false;
}

void ReferenceManager::print() {
	for (int count = 0; count < size_track; count++) {
		cout << endl;
		reference_array[count]->print();
		cout << endl;
	}
}


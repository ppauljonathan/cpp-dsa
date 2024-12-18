#include <iostream>
#include <stdexcept>

template <class T>
class DynamicArray {
public:
  DynamicArray(int cap = 1) {
    if(cap < 1) { throw std::invalid_argument("must be greater than 0"); }

    capacity = cap;
    array = new T[capacity];
  }

  ~DynamicArray() {
    delete array;
  }

  void push(int n) {
    if(length == capacity) { resize(); }

    array[length] = n;
    length++;
  }

  void pop() {
    array[length - 1] = 0;
    length--;

    if(length <= capacity / 2) { resizeDown(); }
  }



  int getCapacity() { return capacity; }
  int getLength() { return length; }

  T getIndex(int index) {
    if(index >= length) { throw std::invalid_argument("out of range"); }

    return array[index];
  }

  void display() {
    std::cout << "{ capacity: " << getCapacity() << ", length: " << getLength() << " } ";
    std::cout << "[ ";
    for(int i = 0; i < length; i++) {
      std::cout << array[i] << " ";
    }
    std::cout << "]\n";
  }

protected:
  T *array;
  int capacity = 0, length = 0;

  void resize() {
    T *new_array = new T[capacity *= 2];
    copyArray(new_array);
  }

  void resizeDown() {
    T *new_array = new T[length];
    capacity = length;
    copyArray(new_array);
  }

  void copyArray(T *new_array) {
    for(int i = 0; i < length; i++) {
      new_array[i] = array[i];
    }

    delete array;
    array = new_array;
  }
};

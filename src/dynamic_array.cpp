#include <iostream>

using namespace std;

template <class T>
class DynamicArray {
  public:
    DynamicArray(int cap = 1) {
      if(cap < 1) { cout<<"capacity must be atleast 1\n"; exit(1); }

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
      if(index >= length) { return NULL; }

      return array[index];
    }

    void display() {
      cout << "{ capacity: " << getCapacity() << ", length: " << getLength() << " } ";
      cout << "[ ";
      for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
      }
      cout << "]\n";
    }

  private:
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

int main() {
    DynamicArray<char> darr(20);

    for(int i = 0; i < 60; i++) {
      darr.push(i+65);
      darr.display();
    }

    for(int i = 0; i < 50; i++) {
      darr.pop();
      darr.display();
    }

    darr.display();
    return 0;
}
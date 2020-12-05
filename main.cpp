#include <iostream>

#include "lock.cpp"
#include "myArray.cpp"

using namespace std;

void getMessageInfo(MyArray* myArray, int index){
    Lock myLock(myArray->getMutex());
    myArray->printMessage(index);
}

MyArray* createMyArray(std::mutex* m){
    return new MyArray(m);
}

int main() {
    std::mutex m;
    std::auto_ptr<MyArray> myArray(createMyArray(&m));

    getMessageInfo(myArray.get(), 5);

    return 0;
}

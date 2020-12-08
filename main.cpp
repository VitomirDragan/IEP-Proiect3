#include <iostream>
#include <mutex>
#include <memory>

#include "lock.cpp"
#include "myArray.cpp"

using namespace std;

void getMessageInfo(MyArray* myArray, int index){
    Lock myLock(myArray->getMutex()); // constructorul clasei Lock va bloca mutexul primit ca si parametru. Acesta va fi eliberat in destructorul clasei.
    myArray->printMessage(index);
}

MyArray* createMyArray(std::mutex* m){
    return new MyArray(m); //implementare metoda de tip factory
}
 
int main() {
    std::mutex m; //declarare mutex, se utilizeaza clasa predefinita biblioteca mutex
    std::auto_ptr<MyArray> myArray(createMyArray(&m)); // ne folosim de smart pointer pentru a gestiona resursele

    getMessageInfo(myArray.get(), 5); //afisare rezultat pentru index 5

    return 0;
}

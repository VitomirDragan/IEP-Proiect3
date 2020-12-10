#include <iostream>
#include <mutex>
#include "Uncopyable.h"

class Lock : private Uncopyable// clasa definita pentru a gestiona blocare si deblocarea unui mutex
{
public:
    explicit Lock(std::mutex *pm) : mutexPtr(pm) 
    {
        try 
        {
            mutexPtr->lock(); // mutexul primit ca si parametru se blocheaza in constructorul clasei
        }catch (std::exception& e)
        {
            std::cout << e.what() << "\n";
        }
    }

    ~Lock() { mutexPtr->unlock(); } // deblocarea mutex-ului se face in destructorul clasei. Astfel se asigura faptul ca un mutex blocat va fi si deblocat

private:
    std::mutex *mutexPtr;
};

class Lock {
public:
    explicit Lock(std::mutex *pm) : mutexPtr(pm) {
        try {
            mutexPtr->lock();
        }catch (std::exception& e){
            std::cout << e.what() << "\n";
        }
    }

    ~Lock() { mutexPtr->unlock(); }

private:
    std::mutex *mutexPtr;
};
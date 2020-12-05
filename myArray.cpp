class MyArray {
private:
    std::mutex* myMutex;
    const static int maxSize = 10;

    class Message {
    private:
        std::string destination;
        std::string message;

    public:
        Message(const std::string &destination, const std::string &message) : destination(destination),
                                                                              message(message) {}

        const std::string &getDestination() const {
            return destination;
        }

        const std::string &getMessage() const {
            return message;
        }
    } *messages[maxSize];

public:
    MyArray(std::mutex* m) : myMutex(m) {
        for (int i = 0; i < maxSize; i++) {
            messages[i] = new Message("Dest" + std::to_string(i), "Message" + std::to_string(i));
        }
    }

    void printMessage(int index) {
        if (index < 0 || maxSize <= index) {
            return;
        }

        std::cout << "Message " << messages[index]->getMessage() << " is for " << messages[index]->getDestination()
                  << "\n";
    }

    std::mutex *getMutex() {
        return myMutex;
    }
};
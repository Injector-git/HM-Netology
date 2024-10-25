#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintCon: public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
   }
private:

};

class PrintFile : public LogCommand {
public:
    PrintFile(std::string filename) {
        file_.open(filename);

        if (!file_.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filename);
        }
    };

    void print(const std::string& message) override {
        
        file_ << message;
        file_ << std::endl;
        
    }
private:
    std::ofstream file_;

};

void print(LogCommand& lc) {
    lc.print("Message");
}
int main()
{
    PrintCon Con;
    PrintFile File("Out.txt");

    print(Con);
    print(File);

}


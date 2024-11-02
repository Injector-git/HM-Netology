#include <iostream>
#include <fstream>

enum Type
{
    fatalerror = 0,
    error = 1,
    warning = 2,
    unknowmerror = 3
};

class LogMessage {
public:
    LogMessage() {
        _type = fatalerror;
        _message = "unknown";
    }
    LogMessage(Type type, std::string const& message) : _type(type), _message(message) {};

    Type type() const {
        return _type;
    }

    const std::string& message() const {
        return _message;
    }

private:
    Type _type = fatalerror;
    std::string _message;
};

class LogHandler {
public:
    void receiveMessage(const LogMessage& msg) {
        //проверяем, можем мы обработать данный тип сообщения
        if (canHadle() == msg.type()) {
            handleMessage(msg); //ок, обработали и закончили цепочку
        }
        else if (next_) //если не обработали, то рекурсивно отправляем следующему хендлеру
        {
            next_->receiveMessage(msg);
        }
        else
        {
            //никто не смог обработать сообщение, выбрасываем ошибку
            throw(std::runtime_error("Error: no handler for this message was found!"));
        }
    }

protected:
    void virtual handleMessage(const LogMessage& msg) = 0; //вызвать обработчик
    virtual Type canHadle() const = 0; //может ли принять такой тип
private:
    LogHandler* next_; //указатель на следующего обработчика
};


class FatalError : public LogHandler {
public:
    Type canHadle() const override {
        return _type;
    }
    void handleMessage(const LogMessage& msg) override {
        throw(std::runtime_error(msg.message()));// выбрасывание исключения с текстом сообщения
    }
private:
    Type _type = fatalerror;
};

class Error : public LogHandler {
public:

    Error(std::string filename) {
        file_.open(filename);

        if (!file_.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filename);
        }
    };

    Type canHadle() const override {
        return _type;
    }
    void handleMessage(const LogMessage& msg) override {
        file_ << msg.message();//в файл
        file_ << std::endl;
    }

private:
    Type _type = error;
    std::ofstream file_;
};

class Warning : public LogHandler {
public:
    Type canHadle() const override {
        return _type;
    }
    void handleMessage(const LogMessage& msg) override {
        std::cout << msg.message() + " war" << std::endl;// в консоль
    }
private:
    Type _type = warning;
};


class UnknowmError : public LogHandler {
public:
    Type canHadle() const override {
        return _type;
    }
    void handleMessage(const LogMessage& msg) override {
        throw std::runtime_error("raw message"); // выбрасывание исключения с текстом о необработанном сообщении
    }
private:
    Type _type = unknowmerror;
};

int main()
{
    LogMessage message(error, "test");
    LogHandler* fatalerr = new FatalError;
    LogHandler* err = new Error("out.txt");
    LogHandler* war = new Warning();
    LogHandler* unk = new UnknowmError();
    

    try {
        fatalerr->receiveMessage(message);
        err->receiveMessage(message);
    }
    catch (std::runtime_error& err) { std::cout << err.what() << std::endl; }
    catch (...) { std::cout << "Unknown error"; }
    

}

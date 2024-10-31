#include <iostream>

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

    virtual void print() = 0;
    virtual void setNextType(LogMessage* type) = 0;

private:
    Type _type = fatalerror;
    std::string _message;
    int asd = 3;
};

class FatalError : public LogMessage {
public:

    void setNextType(LogMessage* type) {
        nextType = type;
    }
    void print() override {
        if (type() == _type) {
            std::cout << message() + "fatalErr" << std::endl;// в консоль
        }
        else {
            nextType->print();
        }
    }
private:
    LogMessage* nextType;
    Type _type = fatalerror;
};

class Error : public LogMessage {

    void setNextType(LogMessage* type) {
        nextType = type;
    }
    void print() override {
        if (type() == _type) {
            std::cout << message() + "Err" << std::endl;// в консоль
        }
        else {
            nextType->print();
        }
    }
private:
    LogMessage* nextType;
    Type _type = error;
};

class Warning : public LogMessage {
public:

    void setNextType(LogMessage* type) {
        nextType = type;
    }
    void print() override {
        if (type() == _type) {
            std::cout << message() + "War" << std::endl;// в консоль
        }
        else {
            nextType->print();
        }
    }
private:
    LogMessage* nextType;
    Type _type = warning;
};


class UnknowmError : public LogMessage {
public:

    void setNextType(LogMessage* type) {
        nextType = type;
    }
    void print() override {
        if (type() == _type) {
            std::cout << message() + "War" << std::endl;// в консоль
        }
        else {
            nextType->print();
        }
    }
private:
    LogMessage* nextType;
    Type _type = unknowmerror;
};
int main()
{
    LogMessage message(error, "test");
    FatalError* fatal = new FatalError();
    Error* error = new Error();
    Warning* war = new Warning();
    UnknowmError* unk = new UnknowmError();
    fatal->setNextType(error);
    error->setNextType(war);
    war->setNextType(unk);
   /* auto message = std::make_unique<LogMessage>(error, "test");
    auto fatal = std::make_shared<FatalError>;
    auto error = std::make_shared<Error>;
    auto war = std::make_unique<Warning>;
    auto unk = std::make_unique<UnknowmError>;*/

}

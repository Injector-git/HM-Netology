#include <iostream>
#include <vector>
#include <fstream>

//наблюдатель
class Observer {
public:

    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}

};

//наблюдаемый
class Observed {
public:
    void warning(const std::string& message) const {
        for (auto observer : observers_) {
            observer->onWarning(message);
        }
    }
    void error(const std::string& message) const {
        for (auto observer : observers_) {
            observer->onError(message);
        }
    }
    void fatalError(const std::string& message) const {
        for (auto observer : observers_) {
            observer->onFatalError(message);
        }
    }

    void AddObserver(Observer* observer) {
        observers_.push_back(observer);
    }

    void RemoveObserver(Observer* observer) {
        auto it = std::remove(observers_.begin(), observers_.end(), observer);
        observers_.erase(it, observers_.end());
    }

private:
    std::vector<Observer*> observers_;
};

class Warning : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << message << std::endl;// в консоль
    }
};

class Error : public Observer {
public:
    Error(std::string filename) {
        file_.open(filename);

        if (!file_.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filename);
        }
    };

    void onError(const std::string& message) override {

        file_ << message;//в файл
        file_ << std::endl;

    }
private:
    std::ofstream file_;
};

class FatalError : public Observer {
public:
    FatalError(std::string filename) {
        file_.open(filename);

        if (!file_.is_open()) {
            throw std::runtime_error("Не удалось открыть файл: " + filename);
        }
    };


    void onFatalError(const std::string& message) override {

        std::cout << message << std::endl;//в консоль
        file_ << message;//в файл
        file_ << std::endl;

    }
private:
    std::ofstream file_;
};


int main()
{
    Warning war;
    Error err("out.txt");
    FatalError ferr("out.txt");

    Observed predmet_nablyudeniya;

    predmet_nablyudeniya.AddObserver(war);
    predmet_nablyudeniya.AddObserver(err);
    predmet_nablyudeniya.AddObserver(ferr);

    predmet_nablyudeniya.warning("Warning!!!");
    predmet_nablyudeniya.error("Error!!!");
    predmet_nablyudeniya.fatalError("Colapse!!!!");

    predmet_nablyudeniya.RemoveObserver(war);
    predmet_nablyudeniya.RemoveObserver(err);
    predmet_nablyudeniya.RemoveObserver(ferr);
}

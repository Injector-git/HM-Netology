#include <fstream>

class Data
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };
    Data() = default;
    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}
protected:
    std::string data_;
    Format format_;
};

class Printable : public Data {
public:
    explicit Printable(Printable* printable) {
        printble_ = printable;
    }
    virtual std::string print() const = 0;
private:
    Printable* printble_;
};


class PrintAsHTML : public Printable {

    explicit PrintAsHTML(Printable* data) : Printable(data) {};
    std::string print() const override {
        return "<html>" + data_ + "<html/>";
    }
};

class PrintAsText : public Printable {

    explicit PrintAsText(Printable* data) : Printable(data) {};
    std::string print() const override {
        return data_;
    }
};

class PrintAsJSONL : public Printable {

    explicit PrintAsJSONL(Printable* data) : Printable(data) {};
    std::string print() const override {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

void saveTo(std::ofstream& file, const Printable* printable, Printable::Format format)
{

    switch (format)
    {
    case Printable::Format::kText:
        file << printable->print();
        break;
    case Printable::Format::kJSON:
        file << printable->print();
        break;
    case Printable::Format::kHTML:
        file << printable->print();
        break;
    }
}

void saveToAsHTML(std::ofstream& file, const Printable* printable) {
    saveTo(file, printable, Printable::Format::kHTML);
}

void saveToAsJSON(std::ofstream& file, const Printable* printable) {
    saveTo(file, printable, Printable::Format::kJSON);
}

void saveToAsText(std::ofstream& file, const Printable* printable) {
    saveTo(file, printable, Printable::Format::kText);
}
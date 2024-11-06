#include <fstream>
#include <vector>

struct Report
{
    std::string date;
    std::string title;
    std::string content;
};

class Printer : public Report {
public:
    virtual ~Printer() = default;
    virtual std::string wrap_element(const std::string& data) const = 0;
    virtual std::string wrap_report(const std::vector<std::string>& elements) const = 0;
};


class PrinterHTML : public Printer {
public:
    std::string wrap_element(const std::string& data) const override {
        return "<p>" + data + "</p>";
    }
    std::string wrap_report(const std::vector<std::string>& elements) const override {
        //TODO: склейка элементов через новую строку и оборачивание в html-тег
    }
};

class PrinterJSON : public Printer {
public:
    std::string wrap_element(const std::string& data) const override {
        return "{ \"item\": \"" + data + "\"}";
    }
    std::string wrap_report(const std::vector<std::string>& elements) const override {
        //TODO: склейка элементов через , и оборачивание в массив - [ elem1, elem2 ]
    }
};

class PrinterText : public Printer {
public:
    std::string wrap_element(const std::string& data) const override {
        return data;
    }
    std::string wrap_report(const std::vector<std::string>& elements) const override {
        std::string Concatenation;
        for (int i = 0; i < elements.size(); i++) {
            Concatenation += elements.at(i);
            Concatenation += "\n";
        }
        return Concatenation;
    }
};

void ReportFormatter(std::ofstream& file, Report& report, std::shared_ptr<Printer> printer)
{
    std::vector<std::string> elements;
    elements.push_back(printer->wrap_element(report.date));
    elements.push_back(printer->wrap_element(report.title));
    elements.push_back(printer->wrap_element(report.content));
    file << printer->wrap_report(elements);
}

int main() {
    Report rep{ "06.11.2024", "Test", "NoContent" };
    std::ofstream file("out.txt");
    auto pr = std::make_shared <PrinterText>();

    ReportFormatter(file, rep, pr);
}
#include <iostream>
#include <iterator>
#include <string>
#include <regex>

class Date {
public:
    Date() {};
    ~Date() {};
    Date(const std::string &date_string);

    void setDate(const std::string& new_date);
    std::string getDate() const;
private:
    std::string date;
};
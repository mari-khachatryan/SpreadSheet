#include <iostream>
#include "Date.h"
#include <string>

enum class Color { Red = 1, Green, Blue}; 

class Cell {
public:
    Cell();
    Cell(const std::string& value, const Color& color);
    ~Cell();
    void setValue(const std::string& new_value);
    std::string getValue() const;

    void setEnum(Color color);
    Color getEnum() const;

    int toInt(const std::string& str);
    double toDouble(const std::string& str);
    std::string  toDate();
    void reset();

private:
    std::string m_value;
    Color m_color;
};
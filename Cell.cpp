#include "Cell.h"

Cell::Cell() {}

Cell::~Cell() {}

Cell::Cell(const std::string& value, const Color& color)
    : m_value{value}
    , m_color{color} {}

void Cell::setValue(const std::string& new_value) {
    m_value = new_value;
}

std::string Cell::getValue() const {
    return m_value;
}

void Cell::setEnum(Color color) {
    m_color = color;
}

Color Cell::getEnum() const {
    return m_color;
}

int Cell::toInt(const std::string& str) {
    return stoi(str);
}

double Cell::toDouble(const std::string& str){
    return stod(str);
}

std::string  Cell::toDate() {
    Date d("02.06.2020");
    m_value = d.getDate();
    return m_value;
}

void Cell::reset() {
    m_value = "";
}
#include <iostream>
#include <vector>
#include "Cell.h"

class SpreadSheet {
public:
    SpreadSheet();
    SpreadSheet(int, int);
    ~SpreadSheet();

    int getRow();
    int getColumn();
    void SetCellAt(int r, int c, const Cell& cl);
    void SetCellAt(int r, int c, const std::string& cl);
    Cell getCellAt(int r, int c) const;
    void addRow(int r);
    void removeRow(int r);
    void addColomn(int c, const std::vector<Cell>& col);
    void removeColumn(int c);
    void swapRows(int r1, int r2);
    void swapColumn(int c1, int c2);
private:
    std::vector<std::vector<Cell>> m_cell;
    int row;
    int column;
};
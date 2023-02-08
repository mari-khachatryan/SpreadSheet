#include <string>
#include "SpreadSheet.h"

SpreadSheet::SpreadSheet() {}
SpreadSheet::SpreadSheet(int new_row, int new_column) 
    :row{new_row}
    ,column{new_column}
{
    Cell cl("-", Color::Blue);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < column; ++j) 
        m_cell[i][j] = cl;          
    }
}

SpreadSheet::~SpreadSheet() {}

int SpreadSheet::getRow() {
    return row;
}

int SpreadSheet::getColumn() {
    return column;
}

void  SpreadSheet::SetCellAt(int r, int c, const Cell& cl){
    m_cell[r][c] = cl;
}

void  SpreadSheet::SetCellAt(int r, int c, const std::string& cl) {
    Cell cell;
    cell.setValue(cl);
    m_cell[r][c] = cell;
}

Cell  SpreadSheet::getCellAt(int r, int c) const {
    return m_cell[r][c];
}

void  SpreadSheet::addRow(int r) {
    Cell c("-", Color::Blue);
    std::vector<Cell> rw(column, c);
    m_cell.insert(m_cell.begin() + r, rw);
}

void  SpreadSheet::removeRow(int r) {
    m_cell.erase(m_cell.begin() + r);
}

void   SpreadSheet::addColomn(int c, const std::vector<Cell>& col) {
    for (int i = 0; i < row; ++i) {
        	m_cell[i].resize(column + 1);
        	for (int j = column; j > c; --j) {
            		m_cell[i][j] = m_cell[i][j-1];
        	}
        	m_cell[i][c] = col[i];
    	}
}

void   SpreadSheet::removeColumn(int c) {
    for (int i = 0; i < row; ++i) {
        	for (int j = c; j < column - 1; ++j) {
            		m_cell[i][j] = m_cell[i][j+1];
        	}
        	m_cell[i].resize(column - 1);
    	}
}

void  SpreadSheet::swapRows(int r1, int r2) {
    std::vector<Cell> tmp = m_cell[r1];
    m_cell[r1] = m_cell[r2];
    m_cell[r2] = tmp;
}

void   SpreadSheet::swapColumn(int c1, int c2) {
    for (int i = 0; i < row; ++i) {
		Cell tmp = m_cell[i][c1];
		m_cell[i][c1] = m_cell[i][c2];
		m_cell[i][c2] = tmp;
	}
}
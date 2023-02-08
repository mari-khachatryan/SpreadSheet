#include <iostream>
#include "test.h"

int main() {
    Test t;
    t.testSetValue();
    t.testGetValue();
    t.testToInt();
    t.testToDouble();
    t.testToDate();
    t.testToReset();
    t.testSetCellAt();
    t.testGetCellAt();
    t.testaddRow();
    t.testremoveRow();
    t.testaddColomn();
    t.testremoveColumn();
    t.testswapRows();
    t.testswapColumn();
	
    return 0;
}
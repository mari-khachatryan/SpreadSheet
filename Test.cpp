#include <iostream>
#include <string>
#include <typeinfo>
#include "test.h"

void Test::testSetValue() {
    Cell c;
    c.setValue("88");
    if(c.toInt(c.getValue()) != 88) {
        std::cout << "TestSetValue failed" << std::endl;
    } else {
        std::cout << "TestSetValue pasted" << std::endl;
    }

    Cell c1;
    c1.setValue("-90");
    if(c1.toInt(c1.getValue()) != -90) {
       std::cout << "TestSetValue failed" << std::endl;
    } else {
        std::cout << "TestSetValue pasted" << std::endl;
    }

    Cell c2;
    c2.setValue("abc");
    if(c2.getValue() == "abc") {
       std::cout << "TestSetValue failed" << std::endl;
    } else {
        std::cout << "TestSetValue pasted" << std::endl;
    }
}

 
void Test::testGetValue() {
    Cell c;
    c.setValue("88");
    if(c.toInt(c.getValue()) != 88) {
        std::cout << "TestGetValue failed" << std::endl;
    } else {
        std::cout << "TestGetValue pasted" << std::endl;
    }

    Cell c1;
    c1.setValue("-90");
    if(c1.toInt(c1.getValue()) != -90) {
       std::cout << "TestGetValue failed" << std::endl;
    } else {
        std::cout << "TestGetValue pasted" << std::endl;
    }

    Cell c2;
    c2.setValue("abc");
    if(c2.getValue() == "abc") {
       std::cout << "TestGetValue failed" << std::endl;
    } else {
        std::cout << "TestGetValue pasted" << std::endl;
    }
}

void Test::testToInt() {
    Cell c;
    c.setValue("5");
    if(typeid(c.toInt("5")).name() == "int") {
         std::cout << "TestToInt failed" << std::endl;
    } else {
        std::cout << "TestToInt pasted" << std::endl;
    }
}

void Test::testToDouble() {
    Cell c;
    c.setValue("5.5");
    if(typeid(c.toDouble("5.5")).name() == "double") {
         std::cout << "TestToDouble" << std::endl;
    } else {
        std::cout << "TestToDouble pasted" << std::endl;
    }
}

void Test::testToDate() {   
    Date date;
     try {
        Date date("2023-02-07");
        std::cout << date.getDate() << std::endl;
        std::cout << "TestToDate pasted" << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        std::cout << "TestToDate failed" << std::endl;
    }
}

void Test::testToReset() {
    Cell c;
    c.setValue("H");
    c.reset();
    if(c.getValue() != "") {
        std::cout << "TestToReset failed" << std::endl;
    } else {
        std::cout << "TestToReset pasted" << std::endl;
    }
}

void Test::testSetCellAt() {
    SpreadSheet sp(2, 2);
    Cell c("10", Color::Blue);
    sp.SetCellAt(1, 1, c);

    if(sp.getCellAt(1, 1).getValue() != c.getValue()) {
        std::cout << "TestSetCellAt failed" << std::endl;
    } else {
        std::cout << "TestSetCellAt pasted" << std::endl;
    }
}

// void Test::testSetCellAt() {
//     SpreadSheet sp(2, 2);
//     sp.setCellAt(1, 1, "mar");

//     if(sp.getCellAt(1, 1).getValue() != "mar") {
//         std::cout << "TestSetCellAt failed" << std::endl;
//     } else {
//         std::cout << "TestSetCellAt pasted" << std::endl;
//     }
// }

void Test::testGetCellAt() {
    SpreadSheet sp(3, 3);
    sp.SetCellAt(1, 1, "h");
    if(sp.getCellAt(1, 1).getValue() != "h") {
        std::cout << "TestGetCellAt failed" << std::endl;
    } else {
        std::cout << "TestGetCellAt pasted" << std::endl;
    }
}

void Test::testaddRow() {
    SpreadSheet sp(2, 2);
    int size = sp.getRow();
    sp.addRow(2);
    int new_size = sp.getRow();
    if(new_size != size + 1 ) {
         std::cout << "TestaddRow failed" << std::endl;
    } else {
        std::cout << "TestaddRow pasted" << std::endl;
    }
}

void Test::testremoveRow() {
    SpreadSheet sp(2, 2);
    int size = sp.getRow();
    sp.removeRow(0);
    int new_size = sp.getRow();
    if(new_size != size - 1 ) {
         std::cout << "TestremoveRow failed" << std::endl;
    } else {
        std::cout << "TestremoveRow pasted" << std::endl;
    }
}

void Test::testaddColomn() {
    SpreadSheet sp(3,3);
	int cols = sp.getColumn();
    	Cell c1("10", Color::Red);
    	Cell c2("20", Color::Red);
    	Cell c3("30", Color::Red);
	std::vector<Cell> newCol = {c1, c2, c3};
	sp.addColomn(2, newCol);
    	int new_cols = sp.getColumn();
    	if (new_cols == cols + 1) {
        	std::cout << "TestaddColomn passed" << std::endl;
    	} 
	else {
        	std::cout << "TestaddColomn failed" << std::endl;
    	}
}
void Test::testremoveColumn() {
    SpreadSheet sp(4, 4);
    int col = sp.getColumn();
    sp.removeColumn(3);
    int new_col = sp.getColumn();
    if (new_col != col - 1) {
        	std::cout << "TestremoveColumn passed" << std::endl;
    	} 
	else {
        	std::cout << "TestremoveColumn failed" << std::endl;
    	}
}

void Test::testswapRows() {
    SpreadSheet sp(3, 3);
    int r = sp.getRow();
    int c = sp.getColumn();
    bool is_swaped = true; 
    for(int i = 0; i < c; ++i) {
        sp.SetCellAt(0, i, "h");
    }
    for(int i = 0; i < c; ++i) {
        sp.SetCellAt(1, i, "m");
    }
    sp.swapRows(0, 1);
    for(int i = 0; i < c; ++i) {
        if(sp.getCellAt(0, i).getValue() != "m") {
            is_swaped = false;
            break;
        }
    }
    for(int i = 0; i < c; ++i) {
        if(sp.getCellAt(1, i).getValue() != "h") {
            is_swaped = false;
            break;
        }
    }
    if (is_swaped) {
        	std::cout << "TestswapRows passed" << std::endl;
    	} 
    	else {
        	std::cout << "TestswapRows failed" << std::endl;
    	}

}

void Test::testswapColumn() {
    SpreadSheet sp(3, 3);
    sp.SetCellAt(0, 0, "M");
    sp.SetCellAt(0, 1, "T");
    sp.swapColumn(0, 1);
    if(sp.getCellAt(0, 0).getValue() != "T" && sp.getCellAt(0, 1).getValue() != "M") {
        std::cout << "TestswapColumn passed" << std::endl;
    } 
    else {
        std::cout << "TestswapColumn failed" << std::endl;
    }

}

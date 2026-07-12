#ifndef __COMPILER_SCANNER_CPP_H__
#define __COMPILER_SCANNER_CPP_H__ 

#include "compiler_scanner.hpp"
#include <iostream>
#include <istream>

class ScannerCPP : public Scanner
{
    public:
        ScannerCPP(std::istream& = std::cin);
        virtual ~ScannerCPP();
};
#endif /* ifndef __COMPILER_SCANNER_CPP_H__ */

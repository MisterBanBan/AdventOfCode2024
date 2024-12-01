#ifndef DAYSONE_HPP
#define DAYSONE_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>

class DaysOne
{
    public:
        DaysOne(void);
        ~DaysOne(void);
        
    private:
        std::vector<int> _data;
        std::vector<int> _data2;
        size_t result;

        void _parseData(std::ifstream &filetxt);
};

#endif

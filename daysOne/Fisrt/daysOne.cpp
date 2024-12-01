#include "daysOne.hpp"

DaysOne::DaysOne(void) : result(0)
{ 
    std::string text = "text.txt";
    std::ifstream file(text.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << text << std::endl;
        return;
    }
    _parseData(file);
    file.close();
}

DaysOne::~DaysOne(void) { }

void DaysOne::_parseData(std::ifstream &filetxt)
{
    std::string line;

    while (std::getline(filetxt, line))
    {
        std::stringstream ss(line);
        int value1, value2;
        //Use to extract value
        if (!(ss >> value1 >> value2))
        {
            std::cerr << "Error: Malformed line -> " << line << std::endl;
            continue;
        }

        _data.push_back(value1);
        _data2.push_back(value2);
    }

    // sort list
    std::sort(_data.begin(), _data.end());
    std::sort(_data2.begin(), _data2.end());

    // Calculate 
    for (size_t i = 0; i < _data.size() && i < _data2.size(); ++i)
        result += std::abs(_data[i] - _data2[i]);

    std::cout << "Total distance: " << result << std::endl;
}

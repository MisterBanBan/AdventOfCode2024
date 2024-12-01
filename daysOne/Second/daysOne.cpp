#include "daysOne.hpp"

DaysOne::DaysOne(void) : similarityScore(0)
{
    std::string text = "text.txt";
    std::ifstream file(text.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << text << std::endl;
        return;
    }
    parseData(file);
    file.close();
}

DaysOne::~DaysOne() {}

void DaysOne::parseData(std::ifstream &filetxt) 
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

    // Comptage des occurrences dans la liste de droite
    for (size_t i = 0; i < _data.size(); ++i) 
        frequencyMap[_data[i]]++;
    calculateSimilarityScore();
}

void DaysOne::calculateSimilarityScore() {
    for (size_t i = 0; i < _data2.size(); ++i)
    {
        int count = 0;
        if (frequencyMap.find(_data2[i]) != frequencyMap.end())
        {
            count = frequencyMap[_data2[i]];
        }
        similarityScore += static_cast<long long>(_data2[i]) * count;
    }

    std::cout << "Score de similarité total : " << similarityScore << std::endl;
}

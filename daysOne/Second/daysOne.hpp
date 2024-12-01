#ifndef DAYSONE_HPP
#define DAYSONE_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class DaysOne
{
    public:
        DaysOne(void);
        ~DaysOne();

        void calculateSimilarityScore();

    private:
        std::vector<int> _data;
        std::vector<int> _data2;
        std::map<int, int> frequencyMap;
        long long similarityScore;

        void parseData(std::ifstream &filetxt);
};

#endif

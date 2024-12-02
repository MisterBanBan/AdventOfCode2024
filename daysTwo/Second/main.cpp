#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <fstream>

bool isSafeReport(const std::vector<int>& levels)
{
    if (levels.size() < 2)
        return false;

    bool isIncreasing = levels[1] > levels[0];

    for (size_t i = 1; i < levels.size(); ++i)
    {
        int diff = std::abs(levels[i] - levels[i - 1]);
        if (diff < 1 || diff > 3)
            return false;
        if ((levels[i] > levels[i - 1]) != isIncreasing)
            return false;
    }
    return true;
}

int main()
{
    int safeCount = 0;
    std::string line;
    std::string text = "text.txt";

    std::ifstream file(text.c_str());
    if (!file.is_open())
        std::cerr << "Error: Unable to open file " << text << std::endl;

    while (std::getline(file, line))
    {
        int level;
        std::vector<int> levels;
        std::stringstream ss(line);

        while (ss >> level)
            levels.push_back(level);
        
        if (isSafeReport(levels))
        {
            ++safeCount;
            continue;
        }
        bool dampened_safe = false;
        for (size_t i = 0; i < levels.size(); ++i)
        {
            std::vector<int> reduced_report = levels;
            reduced_report.erase(reduced_report.begin() + i);
            if (isSafeReport(reduced_report))
            {
                dampened_safe = true;
                break;
            }
        }
        if (dampened_safe)
            ++safeCount;
    }
    std::cout << "Nombre de rapports sûrs : " << safeCount << std::endl;

    return 0;
}

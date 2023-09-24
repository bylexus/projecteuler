#include <iostream>
#include <sstream>
#include <vector>
#include "BaseProblem.h"
#include "Problem0001.cpp"
#include "Problem0002_iterative.cpp"
#include "Problem0002_recursive.cpp"
#include "Problem0003.cpp"
#include "Problem0004.cpp"
#include "Problem0005.cpp"
#include "Problem0006.cpp"
#include "Problem0007.cpp"
#include "Problem0008.cpp"
#include "Problem0009.cpp"

int main(int nrOfArgs, char **args)
{
    if (nrOfArgs < 2)
    {
        std::cerr << "Please give a problem number as argument." << std::endl;
        exit(1);
    }

    std::istringstream iss{args[1]};
    int problemNr;
    iss >> problemNr;

    std::vector<BaseProblem *> problems;
    switch (problemNr)
    {
    case 1:
        problems.push_back(new Problem0001);
        break;
    case 2:
        problems.push_back(new Problem0002);
        problems.push_back(new Problem0002_recursive);
        break;
    case 3:
        problems.push_back(new Problem0003);
        break;
    case 4:
        problems.push_back(new Problem0004);
        break;
    case 5:
        problems.push_back(new Problem0005);
        break;
    case 6:
        problems.push_back(new Problem0006);
        break;
    case 7:
        problems.push_back(new Problem0007);
        break;
    case 8:
        problems.push_back(new Problem0008);
        break;
    case 9:
        problems.push_back(new Problem0009);
        break;

    default:
        std::cerr << "Problem not found." << std::endl;
        exit(1);
    }
    for (BaseProblem *p : problems)
    {
        p->start();
        delete p;
    }
    return 0;
}

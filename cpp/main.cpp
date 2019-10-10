#include <iostream>
#include <sstream>
#include <vector>
#include "BaseProblem.cpp"
#include "Problem0001.cpp"
#include "Problem0002_iterative.cpp"
#include "Problem0002_recursive.cpp"
#include "Problem0003.cpp"

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

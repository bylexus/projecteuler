#ifndef EULER_BASE_PROBLEM
#define EULER_BASE_PROBLEM
#include <iostream>
#include <chrono>
#include <string>

using std::cout;
using std::endl;
using std::fixed;

class BaseProblem
{
protected:
    const char *title;
    std::chrono::duration<double> duration{0};

    BaseProblem(const char *title) : title(title)
    {
    }

    virtual void init() {}
    virtual void postProcess() {}
    virtual void run(long &solution) = 0;
    virtual void printSolution(const long &solution)
    {
        cout << "Solution: " << solution << endl;
        cout << "Time elapsed: ";
        cout << fixed;
        cout << duration.count() << "s\n\n";
        cout.unsetf(std::ios::fixed);
    }

public:
    void start()
    {
        cout << title << endl;
        init();
        long solution{0};
        auto start = std::chrono::system_clock::now();
        run(solution);
        auto end = std::chrono::system_clock::now();
        duration = end - start;
        postProcess();
        printSolution(solution);
    }

    virtual ~BaseProblem() {}
};

#endif

#ifndef EULER_BASE_PROBLEM
#define EULER_BASE_PROBLEM
#include <iostream>
#include <chrono>
#include <string>
#include <cstring>

using namespace std;

class BaseProblem
{
protected:
    std::chrono::duration<double> duration{0};

    virtual string getTitle() {
        return "Unknown Problem";
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
        string title = this->getTitle();
        cout << title << endl;
        for (size_t i = 0; i < title.length(); i++) {
            cout << "*";
        }
        cout << "\n\n";

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

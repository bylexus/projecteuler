#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

namespace euler {

    /**
     * Reads a file and returns the single lines in a vector
     */
    void readLines(const string& filename, vector<string> &data) {
        ifstream infile(filename);
        string token;
        while(getline(infile, token)) {
            data.push_back(token);
        }
    }
}

#endif

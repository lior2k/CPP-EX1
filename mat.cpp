#include "mat.hpp"
#include <iostream>
#include <vector>
using namespace ariel;
using namespace std;
const int MAX_CHAR_VAL = 127;
const int MIN_CHAR_VAL = 32;

string ariel::mat(int cols, int rows, char x, char y) {
    if (cols % 2 == 0 or rows % 2 == 0) {
        throw std::invalid_argument("invalid arguement - even number");
    }
    if (cols <= 0 or rows <= 0) {
        throw std::invalid_argument("invalid arguement - 0 or negative number");
    }
    if ((int)x >= MAX_CHAR_VAL or (int)x <= MIN_CHAR_VAL or (int)y >= MAX_CHAR_VAL or (int)y <= MIN_CHAR_VAL) {
        throw std::invalid_argument("invalid arguement - bad char input");
    }
    if (cols - (int)cols != 0 or rows - (int)rows != 0) {
        throw std::invalid_argument("invalid arguement - fraction detected");
    }

    string result;
    vector<vector<char>> carpet;

    // initiallize - fill vector with trash values
    for (int n = 0; n < rows; n++) {
        vector<char> temp;
        carpet.push_back(temp);
        for (int m = 0; m < cols; m++) {
            carpet[n].push_back('0');     
        }
    }

    char toFill = y;
    int u = 0; // upper row index
    int d = rows - 1; // lower row index
    int l = 0; // left column index
    int r = cols - 1; //right column index

    while (u <= d && l <= r) {
        toFill = (toFill == y)? x : y;

        // fill rows
        for (int i = u; i <= r; i++) {
            // carpet[u].insert(carpet[u].begin() + i, toFill);
            // carpet[d].insert(carpet[d].begin() + i, toFill);
            carpet[u][i] = toFill;
            carpet[d][i] = toFill;
        }

        // fill columns
        for (int i = l; i <= d; i++) {
            // carpet[i].insert(carpet[i].begin() + l, toFill);
            // carpet[i].insert(carpet[i].begin() + r, toFill);
            carpet[i][l] = toFill;
            carpet[i][r] = toFill;
        }
        u += 1;
        l += 1;
        d -= 1;
        r -= 1;
    }

    // build the string
    for (int n = 0; n < rows; n++) {
        for (int m = 0; m < cols; m++) {
            if (result.empty()) {
                result = carpet[n][m];
            } else {
                result += carpet[n][m];
            }            
        }
        result += '\n';
    }

    return result;
}



#include "mat.hpp"
#include <iostream>
#include <vector>
using namespace ariel;
using namespace std;
const int MAX_CHAR_VAL = 127;
const int MIN_CHAR_VAL = 32;

/*
- check for throws.
- build a matrix made of vectors.
- fill the matrix starting with outer layer (border) and so on.
- build then return the string.
*/
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
    char toFill = y;
    int u = 0; // upper row index
    int d = rows - 1; // lower row index
    int l = 0; // left column index
    int r = cols - 1; //right column index

    // initiallize - declare and resize inner vectors
    for (int i = 0; i < rows; i++) {
        vector<char> inner_vector;
        inner_vector.resize(cols);
        carpet.push_back(inner_vector);
    }

    // fill matrix
    while (u <= d && l <= r) {
        //swap char
        toFill = (toFill == y)? x : y;

        // fill rows
        for (int i = u; i <= r; i++) {
            carpet[u][i] = toFill;
            carpet[d][i] = toFill;
        }

        // fill columns
        for (int i = l; i <= d; i++) {
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



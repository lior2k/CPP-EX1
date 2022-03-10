#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

string ariel::mat(int cols, int rows, char x, char y) {
    string result = "";
    char carpet[rows][cols];
    char iterations_char;
    int i = 0;

    // fill matrix
    while (i < (int)(rows/2)+1) {
        int j = i;
        int k = i;
        if (i % 2 == 0) {
            iterations_char = x;
        } else {
            iterations_char = y;
        }       
        // fill rows
        while (j < cols - i) {
            carpet[i][j] = iterations_char;
            carpet[rows - 1 - i][j] = iterations_char;
            j += 1;
        }
        // fill columns
        while (k < rows - i) {
            carpet[k][i] = iterations_char;
            carpet[k][cols - 1 - i] = iterations_char;
            k += 1;
        }
        i += 1;
    }
    int n, m;
    for (n = 0; n < rows; n++) {
        for (m = 0; m < cols; m++) {
            result += carpet[n][m];
        }
        result += '\n';
    }

    return result;
}



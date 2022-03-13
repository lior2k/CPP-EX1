#include "mat.hpp"

int main()
{
    char x = 0;
    int cols, rows;
    char a, b;
    while (true) {
        cout << "Press A to use mat function, press B to exit" << endl;
        cin >> x;
        if (x == 'B') {
            break;
        }
        cout << "enter cols" << endl;
        cin >> cols;
        cout << "enter rows" << endl;
        cin >> rows;
        cout << "enter first char" << endl;
        cin >> a;
        cout << "enter second char" << endl;
        cin >> b;
        try {
            cout << ariel::mat(cols, rows, a, b) << endl;
        } catch(exception &ex) {
                cout << ex.what() << endl;
        }
        
    }    
}

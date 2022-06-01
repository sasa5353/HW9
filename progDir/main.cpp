#include <iostream>
#include <fstream>
#include <sstream>
#include "func.h"
#include "rungeKuttas.h"
#include "adamsExtrapolation.h"
#include "adamsInterpolation.h"

int main(int argc, char *argv[]) {
    int variant =  - 1;
    if (argv[1]) {
        std::stringstream convert(argv[1]);
        convert >> variant;
    } else {
        std::cout << "Please, enter some number between 0 and 2." << std::endl;
    }
    
    std::string s;
    switch (variant) {
        case 0 : {
            s = "rk.dat";
            rungeKuttas(s);
            break;
        }
        case 1 : {
            s = "ae.dat";
            adamsExtrapolation(s);
            break;
        }
        case 2 : {
            s = "ai.dat";
            adamsInterpolation(s);
            break;
        }
        default : {
            std::cout << "Wrong argument! 0 - rungeKuttas, 1 - adamsExtrapolation, 2 - adamsInterpolation.";
        }
    }
    fclose (stdin);
    fclose (stdout);
    fclose (stderr);
    return 0;
}

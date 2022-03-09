/*
 * @Author: NeatLii
 * @Date: 2022-03-08
 * @LastEditors: NeatLii
 * @LastEditTime: 2022-03-09
 * @FilePath: \LeetCode\test.cpp
 * @Description:
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stdout, "Uage: %s number\n", argv[0]);
        return 1;
    }
    double inputValue  = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}
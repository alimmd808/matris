#ifndef FUNCTION_H
#define FUNCTION_H

const int MAX = 20;

void gaussJordan(double a[][MAX + 1], int m, int n);
bool inverseMatrix(double a[][MAX], double inv[][MAX], int n);
double determinant(double a[][MAX], int n);

#endif

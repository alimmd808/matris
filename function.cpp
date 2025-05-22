#include <iostream>
#include <iomanip>
#include <cmath>
#include "function.h"

using namespace std;

void gaussJordan(double a[][MAX + 1], int m, int n) {
    for (int i = 0; i < m; ++i) {
        if (a[i][i] == 0) {
            bool found = false;
            for (int j = i + 1; j < m; ++j) {
                if (a[j][i] != 0) {
                    for (int k = 0; k <= n; ++k)
                        swap(a[i][k], a[j][k]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "❌ No unique solution exists.\n";
                return;
            }
        }

        double pivot = a[i][i];
        for (int j = 0; j <= n; ++j)
            a[i][j] /= pivot;

        for (int j = 0; j < m; ++j) {
            if (j != i) {
                double factor = a[j][i];
                for (int k = 0; k <= n; ++k)
                    a[j][k] -= factor * a[i][k];
            }
        }
    }

    cout << "✅ Solution:\n";
    for (int i = 0; i < m; ++i)
        cout << "  x" << i + 1 << " = " << fixed << setprecision(6) << a[i][n] << endl;
}

bool inverseMatrix(double a[][MAX], double inv[][MAX], int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            inv[i][j] = (i == j) ? 1 : 0;
        }

    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0) {
            bool found = false;
            for (int j = i + 1; j < n; ++j) {
                if (a[j][i] != 0) {
                    for (int k = 0; k < n; ++k) {
                        swap(a[i][k], a[j][k]);
                        swap(inv[i][k], inv[j][k]);
                    }
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }

        double pivot = a[i][i];
        for (int j = 0; j < n; ++j) {
            a[i][j] /= pivot;
            inv[i][j] /= pivot;
        }

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = a[j][i];
                for (int k = 0; k < n; ++k) {
                    a[j][k] -= factor * a[i][k];
                    inv[j][k] -= factor * inv[i][k];
                }
            }
        }
    }

    return true;
}

double determinant(double a[][MAX], int n) {
    double temp[MAX][MAX];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            temp[i][j] = a[i][j];

    double det = 1;
    for (int i = 0; i < n; ++i) {
        if (temp[i][i] == 0) {
            bool found = false;
            for (int j = i + 1; j < n; ++j) {
                if (temp[j][i] != 0) {
                    for (int k = 0; k < n; ++k)
                        swap(temp[i][k], temp[j][k]);
                    det *= -1;
                    found = true;
                    break;
                }
            }
            if (!found)
                return 0;
        }

        det *= temp[i][i];
        for (int j = i + 1; j < n; ++j) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = 0; k < n; ++k)
                temp[j][k] -= factor * temp[i][k];
        }
    }

    return det;
}

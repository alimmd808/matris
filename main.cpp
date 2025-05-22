#include <iostream>
#include <iomanip>
#include "function.h"
using namespace std;

int main() {
    while (true) {
        cout << "\n========= Matrix Operations Menu =========\n";
        cout << "1. Solve system of equations (Gauss-Jordan)\n";
        cout << "2. Find inverse of a matrix\n";
        cout << "3. Calculate determinant of a matrix\n";
        cout << "0. Exit\n";
        cout << "==========================================\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "❌ Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                int m, n;
                double a[MAX][MAX + 1];

                cout << "\nEnter number of equations (M): ";
                cin >> m;
                cout << "Enter number of variables (N): ";
                cin >> n;

                if (m <= 0 || n <= 0 || m > MAX || n > MAX) {
                    cout << "❌ M and N must be between 1 and " << MAX << ".\n";
                    break;
                }

                cout << "Enter augmented matrix:\n";
                for (int i = 0; i < m; ++i) {
                    cout << "Equation " << i + 1 << ": ";
                    for (int j = 0; j <= n; ++j)
                        cin >> a[i][j];
                }

                gaussJordan(a, m, n);
                break;
            }

            case 2: {
                int n;
                double a[MAX][MAX], inv[MAX][MAX];
                cout << "\nEnter order of square matrix: ";
                cin >> n;

                if (n <= 0 || n > MAX) {
                    cout << "❌ Matrix size must be between 1 and " << MAX << ".\n";
                    break;
                }

                cout << "Enter matrix:\n";
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        cin >> a[i][j];

                if (inverseMatrix(a, inv, n)) {
                    cout << "✅ Inverse matrix:\n";
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n; ++j)
                            cout << fixed << setprecision(6) << inv[i][j] << " ";
                        cout << endl;
                    }
                } else {
                    cout << "❌ Matrix is not invertible.\n";
                }
                break;
            }

            case 3: {
                int n;
                double a[MAX][MAX];
                cout << "\nEnter order of square matrix: ";
                cin >> n;

                if (n <= 0 || n > MAX) {
                    cout << "❌ Matrix size must be between 1 and " << MAX << ".\n";
                    break;
                }

                cout << "Enter matrix:\n";
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        cin >> a[i][j];

                double det = determinant(a, n);
                cout << "✅ Determinant: " << fixed << setprecision(6) << det << endl;
                break;
            }

            case 0:
                cout << "👋 Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "❌ Invalid choice. Please select between 0 and 3.\n";
        }
    }

    return 0;
}

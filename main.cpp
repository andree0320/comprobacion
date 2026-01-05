#include <iostream>
#include <iomanip>

// Enlace Blas
extern "C" {
void dgemm_(char* transa, 
            char* transb, 
            int* m, int* n, int* k, 
            double* alpha, double* A, 
            int* lda, double* B, int* ldb, 
            double* beta, double* C, int* ldc);
}

int main() 
{ 
    double alpha = 1.0;

    double beta = 0.0;

    char nTrans = 'N';

    int m = 2, n = 2, k = 2;
    
    // Aplicaremos redimensionamiento para eliminar las 3ras filas y columnas y poder obtener A
    double U[9] = {-0.79, -0.38,
                    0.0,  -0.78,};

    double E[9] = {1.62, 0.0, 
                    0.0,  1.0};

    double VT[4] = {-0.78, -0.62,
                     0.62, -0.78};
    
    double Temp[9] = {0};     // U * E

    double A_final[6] = {0};  // (U*E) * VT 

    dgemm_(&nTrans, &nTrans, &m, &n, &k, &alpha, U, &m, E, &k, &beta, Temp, &m);

    dgemm_(&nTrans, &nTrans, &m, &n, &k, &alpha, Temp, &m, VT, &k, &beta, A_final, &m);

    std::cout << "Resultado calculado de A"<< std::endl;

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            std::cout << std::setw(10) << A_final[i + j * 3] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nMatriz A esperada:" << std::endl;
    std::cout << "  1.00  -0.80" << std::endl;
    std::cout << "  0.00   1.00" << std::endl;

    return 0;
}
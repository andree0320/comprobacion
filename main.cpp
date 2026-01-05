#include <iostream>

extern "C" {
    void dgesv_(int* n, int* nrhs, double* A, int* lda, int* ipiv, double* b, int* ldb, int* info);
}

int main()
{
    std::cout<<"Inicializando LAPACK"<<std::endl;

    double A[9] = {4, 2, 3, 3, 7, 1, 2, 1, 8};
    double b[3] = {10, 19, 17};
    int n = 3, nrhs = 1, lda = 3, ldb = 3;
    int ipiv[3], info;

    dgesv_(&n, &nrhs, A, &lda, ipiv, b, &ldb, &info);

    if(info == 0)
    {
        std::cout<<"Solucion: ";

        for(int i = 0; i < n; ++i)
        {
            std::cout<<b[i]<<" ";
        }
        
        std::cout<<std::endl;
    }
    else
    {
        std::cerr<<"Error al resolver el sistema, codigo: "<<info<<std::endl;
    }
    
    return 0;
}
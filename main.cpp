#include "FuncionOcurrencias.h"
#include "ContadorPalabrasLetrasRenglones.h"
#include "OcurrenciasExcluir.h"
#include "OcurrenciasExcluirPalabras.h"
#include "MostrarOcurrencias1.h"
#include "OrdenAlfabetico.h"
#include "Excluir-palabra-alf.h"
#include "Excluir-igntxt.h"
#include<cstring>
int main (int argc, char **argv) {


    cout <<" Has escrito "<< argc << " argumentos"<<endl;
    unsigned t0,t1;

    t0= clock();

    try {

        if (strcmp(argv[1], "texto.txt")==0 && argc == 2)
        {
            Contador_Pal_Let_Ren(argv[1]);
        }
        if (strcmp(argv[1], "-palabras")==0){
            if (strcmp(argv[3], "texto.txt")==0)
            {
                Palabras(argv[3], argv[2]);
            }else if (strcmp(argv[2], "-excluir")==0) {
                ExcluirpalabrasAlf(argv[3], argv[4]);
            }else if (strcmp(argv[2], "-excluirf")==0){
                ExcluirpalabraIgntxt(argv[3], argv[4]);
            }

        }

        if (strcmp(argv[1], "-ocurrencias")==0) {

            if (argc < 4) {


                if (strcmp(argv[2], "texto.txt") == 0) {

                    Ocurrencias(argv[2], "0");

                }
            } else {


                if (strcmp(argv[3], "texto.txt") == 0) {
                    Ocurrencias(argv[3], argv[2]);
                } else if (strcmp(argv[2], "-excluir") == 0) {
                    Excluir(argv[4], argv[3]);
                } else if (strcmp(argv[2], "-excluirf") == 0) {
                    Excluirf(argv[4], argv[3]);
                }
            }
        }else if (strcmp(argv[1], "-mostrar") == 0) {
            Mostrar(argv[3], argv[2]);
        }



    }catch (int e){
        if (e==300){}
    }

    t1=clock();

    double time = (double (t1-t0)/CLOCKS_PER_SEC);

    std::cout<<"Execution Time: " << time << std::endl;
}
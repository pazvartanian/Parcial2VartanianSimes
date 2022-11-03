
#include "FuncionOcurrencias.h"
#include "ContadorPalabrasLetrasRenglones.h"
#include "OcurrenciasExcluir.h"
#include "OcurrenciasExcluirPalabras.h"
#include "OcurrenciasMostrar.h"
#include "OrdenAlfabetico.h"

 int main () {

    unsigned t0,t1;

    t0= clock();

     string igntxt = "C:\\Users\\Usuario\\Desktop\\parcial 2\\Parcial2VartanianSimes\\igntxt";
     std::ifstream file;
     file.open(igntxt,std::ios::in);

     ContPalLetRen();
     int n=0;
     Ocurrencias(n);
     //Excluirf(igntxt);
     std::string palabra;
     //palabra= "hola";
     //Excluir(palabra);
     //Mostrar (palabra);
     Palabras(n);

     t1=clock();

     double time = (double (t1-t0)/CLOCKS_PER_SEC);

     std::cout<<"Execution Time: " << time << std::endl;
 }


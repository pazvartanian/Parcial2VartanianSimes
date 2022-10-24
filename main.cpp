
#include "FuncionOcurrencias.h"
#include "ContadorPalabrasLetrasRenglones.h"
#include "OcurrenciasExcluir.h"
#include "OcurrenciasExcluirPalabras.h"
#include "OcurrenciasMostrar.h"


 int main () {
     string igntxt = "C:\\Users\\Usuario\\Documents\\2do UCC\\Parcial2-SimesVartanian\\igntxt";
     std::ifstream file;
     file.open(igntxt,std::ios::in);

     ContPalLetRen();
     int n=3;
     Ocurrencias( n);
     Excluirf(igntxt);
     std::string palabra;
     palabra= "manuela";
     Excluir(palabra);
     Mostrar (palabra);


 }


#include "Consultas.h"
#include "Evaluacion.h"
void cargarConsulta (Consulta &cons){
   cargarfecha(cons.fe);
   printf("\nIngrese el motivo de la consulta:");
   scanDinamico(cons.motivo);
   printf("\nIngese la cedula:");
   scanf("%ld", &cons.cedula);
   cargarEvaluacion(cons.ev);
}
void mostrarConsulta (Consulta cons){
    mostrarfecha(cons.fe);
    printf("\tMOTIVO DE LA CONSULTA:");
    print(cons.motivo);
    printf("\tCEDULA:");\
    printf("%ld\t", cons.cedula);
    mostrarEvaluacion(cons.ev);
}
Fecha DarFecha (Consulta cons){
    return cons.fe;
}
void DarMotivo (Consulta cons, string &s){
    StrCrear(s);
    strcopDinamico(cons.motivo, s);
}
long int DarCedula (Consulta cons){
    return cons.cedula;
}

void Bajar_Consulta (Consulta c, FILE * f) {
    fwrite (&c.fe, sizeof(Fecha), 1, f);
    Bajar_String(c.motivo, f);
    fwrite (&c.cedula, sizeof(long int), 1, f);
    fwrite (&c.ev, sizeof(Evaluacion), 1, f);
}

void Levantar_Consulta (Consulta &c, FILE * f) {
    StrCrear (c.motivo);
    fread (&c.fe, sizeof(Fecha), 1, f);
    Levantar_String(c.motivo, f);
    fread (&c.cedula, sizeof(long int), 1, f);
    fread (&c.ev, sizeof(Evaluacion), 1, f);
}

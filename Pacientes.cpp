#include "Pacientes.h"

void cargarPaciente (Paciente &pa){
    printf("\nIngrese la cedula del paciente:");
    fflush(stdin);
    scanf("%ld", &pa.cedula);
    printf("\nIngrese el nombre del paciente:");
    fflush(stdin);
    scanDinamico(pa.nombre);
    printf("\nIngrese el apellido del paciente:");
    fflush(stdin);
    scanDinamico(pa.apellido);
    printf("\nIngrese el numero de telefono del paciente:");
    scanf("%d", &pa.telefono);
    pa.cant_consultas=0;
}
void mostrarPaciente (Paciente pa){
    printf("Cedula:");
    printf("%ld", pa.cedula);
    printf("\tNombre:");
    print(pa.nombre);
    printf("\tApellido:");
    print(pa.apellido);
    printf("\tTelefono:");
    printf("%d", pa.telefono);
    printf("\tCantidad de consultas:");
    printf("%d", pa.cant_consultas);
}
long int DarCedula (Paciente pa){
    return pa.cedula;
}
void DarNombre (Paciente pa, string &nombre){
    StrCrear(nombre);
    strcopDinamico (nombre,pa.nombre);
}
void Darapellido (Paciente pa, string &apellido){
    StrCrear(apellido);
    strcopDinamico (apellido, pa.apellido);
}
int DarTelefono (Paciente pa){
    return pa.telefono;
}
int DarCantConsulta (Paciente pa){
    return pa.cant_consultas;
}

void Bajar_Paciente (Paciente P, FILE * f)  {
 fwrite (&P.cedula, sizeof(long int), 1, f);
 Bajar_String (P.nombre, f);
 Bajar_String (P.apellido, f);
 fwrite (&P.telefono, sizeof(int), 1, f);
 fwrite (&P.cant_consultas, sizeof(int), 1, f);
}

void Levantar_Paciente (Paciente &P, FILE * f) {
 StrCrear (P.nombre);
 StrCrear (P.apellido);
 fread (&P.cedula, sizeof(long int), 1, f);
 Levantar_String (P.nombre, f);
 Levantar_String (P.apellido, f);
 fread (&P.telefono, sizeof(int), 1, f);
 fread (&P.cant_consultas, sizeof(int), 1, f);
}

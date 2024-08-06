#include "menu.h"
#include <stdlib.h>

void DesplegarAyB (int &opcion){
printf("\t\t\t\t\t\tALTAS Y BAJAS\n\n");
printf("OPCION 1: REGISTRAR UN PACIENTE EN EL SISTEMA\n");
printf("OPCION 2: REGISTRARLE UNA CONSULTA A UN PACIENTE\n");
printf("OPCION 3: DAR DE BAJA UN PACIENTE\n");
printf("OPCION 4: VOLVER AL MENU PRINCIPAL\n\n");
printf("ELIJA UNA OPCION:");
scanf("%d", &opcion);
}

void DesplegarLis (int &opcion){
printf("\t\t\t\t\t\tLISTADOS\n\n");
printf("OPCION 1: MOSTRAR TODOS LOS PACIENTES EN PANTALLA\n");
printf("OPCION 2: MOSTRAR TODOS LOS PACIENTES SIN CONSULTAS REGISTRADAS EN PANTALLA\n");
printf("OPCION 3: MOSTRAR TODOS LAS CONSULTAS DE UN PACIENTE EN PANTALLA\n");
printf("OPCION 4: MOSTRAR TODAS LAS CONSULTAS A PARTIR DE UNA FECHA EN PANTALLA\n");
printf("OPCION 5: VOLVER AL MENU PRINCIPAL\n\n");
printf("ELIJA UNA OPCION:");
scanf("%d", &opcion);
}

void DesplegarCon (int &opcion){
printf("\t\t\t\t\t\tCONSULTAS\n\n");
printf("OPCION 1: OBTENER LA CANTIDAD DE PACIENTES QUE HAN REALIZADO POR LO MENOS X CANTIDAD DE CONSULTAS\n");
printf("OPCION 2: OBTENER LA CANTIDAD DE CONSULTAS DE CADA TIPO\n");
printf("OPCION 3: OBTENER LA CANTIDAD DE CONSULTAS REALIZADAS EN UNA FECHA\n");
printf("OPCION 4: OBTENER EL PACIENTE CON MAS CONSULTAS REGISTRADAS\n");
printf("OPCION 5: VOLVER AL MENU PRINCIPAL\n\n");
printf("ELIJA UNA OPCION:");
scanf("%d", &opcion);
}

void DesplegarMenu (int &opcion) {
printf("\t\t\t\t\t\tCONSULTORIO ODONTOLOGICO\n\n");
printf("OPCION 1: ALTAS Y BAJAS\n");
printf("OPCION 2: LISTADOS\n");
printf("OPCION 3: CONSULTAS\n");
printf("OPCION 4: SALIR DEL PROGRAMA\n\n");
printf("ELIJA UNA OPCION:");
scanf("%d", &opcion);
}


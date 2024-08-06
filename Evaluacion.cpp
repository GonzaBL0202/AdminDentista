#include "Evaluacion.h"
#include "boolean.h"
void cargarEvaluacion(Evaluacion &ev){
    boolean repetir;
    int opcion;
    do{
    repetir=FALSE;
    printf("EVALUACION DEL PACIENTE:\n");
    printf("1-EN TRATAMIENTO\n");
    printf("2-NECESITA PROTESIS\n");
    printf("3-SALUDABLE\n");
    printf("Ingrese un entero para la evaluacion del paciente:");
    scanf("%d", &opcion);
    switch (opcion){
        case 1: ev=EN_TRATAMIENTO;
                break;
        case 2: ev=NECESITA_PROTESIS;
                break;
        case 3: ev=SALUDABLE;
                break;
        default: repetir=TRUE;
                 printf("Opcion no valida, ingrese nuevamente un entero\n");
                 break;
    }
}while(repetir);
}
void mostrarEvaluacion (Evaluacion ev){
 switch (ev){
        case EN_TRATAMIENTO: printf(" EVALUACION: EN TRATAMIENTO\n");
                             break;
        case NECESITA_PROTESIS: printf(" EVALUACION: NECESITA PROTESIS\n");
                                break;
        case SALUDABLE: printf(" EVALUACION: SALUDABLE\n");
                        break;
    }
}

Evaluacion DarEvaluacion (Evaluacion ev){
    return ev;
}

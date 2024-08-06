#ifndef EVALUACION_H_INCLUDED
#define EVALUACION_H_INCLUDED
#include <stdio.h>

typedef enum {EN_TRATAMIENTO, NECESITA_PROTESIS, SALUDABLE} Evaluacion;

void cargarEvaluacion(Evaluacion &ev);

void mostrarEvaluacion (Evaluacion ev);

Evaluacion DarEvaluacion (Evaluacion ev);

#endif // EVALUACION_H_INCLUDED

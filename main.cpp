#include "menu.h"



int main()
{
  int opcion, opcion1, opcion2, opcion3;
  ABBP ap;
  Lista_Cons LC;
  CrearArbol(ap);
  CrearLista(LC);
  boolean volver=FALSE;
  Paciente p;
  Fecha fe;
  long int cedula;


  if (Existe("Pacientes.dat")) {
    Levantar_ABB(ap, "Pacientes.dat");
  }
  if (Existe("Consultas.dat")) {
    Levantar_Lista(LC, "Consultas.dat");
  }

  //Menu
  do{
  DesplegarMenu(opcion);
  switch(opcion){
  case 1:
         do{
         DesplegarAyB(opcion1);
         switch (opcion1){

            case 1: RegistrarPaciente(ap,p);
                    break;

            case 2: AgregarConsulta(ap,LC);
                    break;

            case 3: printf("Ingrese una cedula para borrarlo del sistema:");
                    scanf("%ld", &cedula);
                    Borrar(cedula, ap);
                    BorrarOcurrencias(LC, cedula);
                    break;
        }
            system("cls");
} while (opcion1 != 4);
         break;

  case 2:
      do{
        DesplegarLis(opcion2);
        switch (opcion2){

        case 1: printf("\t\t\t\t\tPACIENTES REGISTRADOS\n\n");
        ListarPacientes(ap);
        break;

        case 2: printf("\t\t\t\tPACIENTES REGISTRADOS SIN CONSULTAS\n");
        ListarSinConsultas(ap);
        break;

        case 3: long int cedula;
        printf("\nIngrese una cedula para mostrar sus consultas:");
        scanf("%ld", &cedula);
        ListarConsultasPaciente(LC, cedula);
        break;

        case 4: printf("\nIngrese una fecha:");
        cargarfecha(fe);
        ListarPostFecha(LC, fe);
        break;

     //   case 5: volver = TRUE;
       //         system("cls");
         //       break;
    }
    system("pause");
    system("cls");
} while (opcion2 != 5);
         break;


  case 3:
      do{
        DesplegarCon(opcion3);
        switch (opcion3){

        case 1: int cant,cons;
        printf("Ingrese una cantidad de consultas:");
        scanf("%d", &cant);
        cons=CantPacientesXConsultas(ap, cant);
        printf("\nHAY %d PACIENTES CON POR LO MENOS %d CONSULTAS\n", cons, cant);
        break;

        case 2: {int trat=0,prot=0,salu=0;
         CantCadaTipo(LC, trat, prot,salu);
         printf("HAY %d PACIENTES EN TRATAMIENTO, %d PACIENTES QUE NECESITAN PROTESIS Y %d PACIENTES SALUDABLES\n", trat, prot, salu);
         break;
         }

         case 3: cargarfecha(fe);
         printf("\nHAY %d CONSULTAS CARGADAS EN ESA FECHA\n", CantPorFecha(LC, fe));
         break;

         case 4: int consultas;
         consultas= ap->info.cant_consultas;
         cedula= ap->info.cedula;
         MaxConsultas(ap, consultas, cedula);
         printf("\nCEDULA DEL PACIENTE CON MAS CONSULTAS: %ld CON %d CONSULTAS\n", cedula, consultas);
         break;
    }
            system("pause");
            system("cls");
} while (opcion3 != 5);
         break;

    } //switch
  }while(opcion !=4);

  Bajar_ABB(ap, "Pacientes.dat");
  Bajar_Lista(LC, "Consultas.dat");

} //main

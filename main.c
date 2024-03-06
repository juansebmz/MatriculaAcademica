#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int ID;

struct Estudiantes{
    int ID;
    char contrasena[16];
    int creditosFinancieros;
} estudiante[5];

struct Cursos {
    char codigo[6];
    char grupo[6];
    char nombre[45];
    int creditos;
    int anio;
    char ciclo;
    char dia[10];
    double horaInicio;
    double horaFin;
    int cupo;
} curso[10] = {
        {"DSI16", "3B110", "Ingles III", 3, 2024, 'A', "Jueves", 8, 12, 12},
        {"DSI17", "RYC02", "Redes y Comunicaciones", 3, 2024, 'A', "Jueves", 18.30, 21.30, 13},
        {"DSI17", "RYC01", "Redes y Comunicaciones", 3, 2024, 'A', "Miercoles", 18.30, 21.30,14},
        {"DSI18", "SFE02", "Construccion de Software 2", 3, 2024, 'A', "Sabado", 10, 13,12},
        {"DSI19", "POW01", "Programacion Orientada a la Web", 3, 2024, 'A', "Sabado", 13, 16,9},
        {"DSI19", "POW03", "Programacion Orientada a la Web", 3, 2024, 'A', "Sabado", 10, 13,4},
        {"DSI20", "ADI01", "Administracion de la Informacion", 3, 2024, 'A', "Miercoles", 18.30, 21.30,20},
        {"DSI22", "ZRC21", "Razonamiento Cuantitativo", 3, 2024, 'B', "Miercoles", 18.30, 21.30,7},
        {"DSI23", "CCP00", "Constitucion Politica", 2, 2024, 'B', "Lunes", 14, 17,30},
        {"DSI24", "PDM00", "Programacion de Dispositivos Mobiles", 3, 2024, 'B', "Martes", 14, 17,4}
};

struct Cursos cursosMatriculados[10];
int numCursosMatriculados = 0;

void estudiantesActivos(){

    estudiante[0].ID = 1;
    strcpy(estudiante[0].contrasena, "A");
    estudiante[0].creditosFinancieros = 15;

    estudiante[1].ID = 2;
    strcpy(estudiante[1].contrasena, "B");
    estudiante[1].creditosFinancieros = 16;

    estudiante[2].ID = 3;
    strcpy(estudiante[2].contrasena, "C");
    estudiante[2].creditosFinancieros = 14;

    estudiante[3].ID = 4;
    strcpy(estudiante[3].contrasena, "D");
    estudiante[3].creditosFinancieros = 15;

    estudiante[4].ID = 5;
    strcpy(estudiante[4].contrasena, "E");
    estudiante[4].creditosFinancieros = 4;
}

int IngresoID(){
    printf("Ingrese su ID: ");
    scanf("%d", &ID);
    return ID;
}

void matriculaAcademica() {

    int anioUsuario;
    char periodoUsuario;
    int creditosEstudiante;

    for (int i = 0; i < sizeof (estudiante)/ sizeof(estudiante[0]); i++) {
        if (ID == estudiante[i].ID){
            creditosEstudiante = estudiante[i].creditosFinancieros;
        }
    }

    printf("\nIngrese el a%co: ",164);
    scanf("%d", &anioUsuario);

    printf("\nIngrese el periodo academico (A, B, C): ");
    scanf(" %c", &periodoUsuario);

    printf("\nCURSOS OFERTADOS en %d%c", anioUsuario, periodoUsuario);
    printf("\n***********************************************\n");

    for (int i = 0; i < sizeof (estudiante)/sizeof (estudiante[0]); i++) {
        if(ID == estudiante[i].ID){
            printf("Creditos disponibles: %d\n",estudiante[i].creditosFinancieros);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (curso[i].anio == anioUsuario && curso[i].ciclo == periodoUsuario) {
            printf("Codigo: %.5s\n", curso[i].codigo);
            printf("Grupo: %.5s\n", curso[i].grupo);
            printf("Nombre: %s\n", curso[i].nombre);
            printf("Creditos: %d\n", curso[i].creditos);
            printf("Dia: %s\n", curso[i].dia);
            printf("Hora de inicio: %.2lf\n", curso[i].horaInicio);
            printf("Hora de fin: %.2lf\n", curso[i].horaFin);
            printf("Cupos restantes: %d\n\n",curso[i].cupo);
        }
    }

    do {
        char grupoElegido[6];
        printf("Escriba el grupo del curso a matricular (o '0' para salir): \n");
        scanf("%s", grupoElegido);

        if (grupoElegido[0] == '0') {
            printf("Saliendo de la matr%ccula.\n",161);
            break;
        }

        for (int i = 0; i < sizeof(curso) / sizeof(curso[0]); i++) {
            if (strcmp(grupoElegido, curso[i].grupo) == 0) {
                if (curso[i].cupo > 0) {
                    if (creditosEstudiante >= curso[i].creditos) {
                        creditosEstudiante -= curso[i].creditos;
                        estudiante[i].creditosFinancieros = creditosEstudiante;

                        printf("Matr%ccula exitosa en el curso %s - %s\n",161, curso[i].codigo, curso[i].nombre);
                        printf("Cr%cditos restantes: %d\n",130,creditosEstudiante);

                        strcpy(cursosMatriculados[numCursosMatriculados].codigo, curso[i].codigo);
                        strcpy(cursosMatriculados[numCursosMatriculados].nombre, curso[i].nombre);
                        numCursosMatriculados++;
                    } else {
                        printf("Error: No tiene suficientes cr%cditos para este curso.\n",130);
                    }
                } else {
                    printf("Error: El cupo para el curso %s - %s est%c lleno.\n", curso[i].codigo, curso[i].nombre,160);
                }
                break;
            }
        }

        printf("%cDesea matricular m%cs cursos? (1: S%c, 0: No): ",168,160,161);
        int continuarMatricula;
        scanf("%d", &continuarMatricula);

        if (continuarMatricula == 0) {
            printf("Matr%ccula cerrada.\n",161);
            break;
        }

    } while (creditosEstudiante > 0);

    if (numCursosMatriculados > 0) {
        printf("\nCursos matriculados:\n");
        for (int i = 0; i < numCursosMatriculados; i++) {
            printf("- %s: %s\n", cursosMatriculados[i].codigo, cursosMatriculados[i].nombre);
        }
    } else {
        printf("\nNo se ha matriculado en nin%cn curso.\n",163);
    }

}

bool InicioDeSesion(){
    bool comprobar = false;

    char contrasena[16];

    estudiantesActivos();
    printf("Inicie sesi%cn\n",162);

    ID = IngresoID();

    printf("Ingrese su contrasena:");
    scanf(" %s", contrasena);

    for (int i = 0; i < sizeof(estudiante); i++){
        if ((estudiante[i].ID == ID) && (strcmp(estudiante[i].contrasena, contrasena) == 0)){
            comprobar = true;
            break;
        }
    }

    if(comprobar == true){
        printf("Inicio de sesion exitoso\n");

    }else{
        printf("Inicio de sesion fallido\n");
    }

    return comprobar;

}

void menu(){

    printf("\n ******************************************");
    printf("\n 1. Matricula Academica");
    printf("\n\n 0. Salir");
    printf("\n ******************************************\n");
    printf("Escriba su opci%cn:",162);

    int opcion;
    scanf("%i", &opcion);

    switch (opcion) {
        case 1:
            matriculaAcademica();
            break;
        case 0:
            exit(0);
    }
}



int main(void) {
    printf("Bievenido al sistema academico SINU\n");


    bool inicioDeSesionExitoso = InicioDeSesion();

    if (inicioDeSesionExitoso == true) {
        menu();
    } else {
        printf("Incio incorrecto");
        system("pause");
    }

    return 0;
}
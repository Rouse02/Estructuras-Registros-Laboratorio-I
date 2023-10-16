#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//Variables Globales
#define DIMENSION 30

//Estructuras
typedef struct
{
    int matricula;
    char nombre[DIMENSION];
    char genero;
} Alumno;

//Prototipado
void mostrarMenu();//Menú
void continuarMenu(char eleccion);//Menú
int cargarAlumnosHasta(Alumno alumnos[DIMENSION]);//1
Alumno cargaAlumno();//1
void mostrarAlumnos(Alumno alumnos[], int validosAlumno);//2
void mostrarAlumno(Alumno mostrarAlum);//2
void mostrarAlumnoMatricula(Alumno alumnos[], int validos, int matricula);//3
void mostrarAlumnoxMatricula(Alumno alumnos[], int i);//3
int posicionMenor(Alumno alumnos[], int posicion, int validos);//4
void ordenamientoXseleccion(Alumno alumnos[], int validos);//4
void mostrarAlumnosGenero(Alumno alumnos[], int validos, char genero);//5
void mostrarGenero(Alumno alumnos[], int validos, char genero);//5
int insertarNuevoAlumnoOrdenado(Alumno alumnos[], int validos);//6
void insertar(Alumno alumnos[], int posicionBusqueda, Alumno alumnos1);//7
void ordenamientoXinsercion(Alumno alumnos[] , int validos);//7
int contarAlumnosxGenero(Alumno alumnos[], int validos, char genero);//8
int contarxGenero(Alumno alumnos[], int validos, char genero);//8

/*_____________________________________________________________________________________________________________________________________________________________________________________________________________*/

int main() {

    //Variables
    Alumno alumnos[DIMENSION];

    int matricula, ejercicio, validosAlumno, newValidosAlumno;

    char eleccion = 's';
    char genero;


    do {
    mostrarMenu();

    printf("Ingrese el numero de ejercicio a dirigirse ---> ");
    fflush(stdin);
    scanf("%i", &ejercicio);
    printf("\n");

    switch(ejercicio) { //INICIO SWTICH

    case 1:
        validosAlumno = cargarAlumnosHasta(alumnos);

        printf("Cargaste en sistema %i registro/os \n", validosAlumno);
        printf("\n");
    break;


    case 2:
        mostrarAlumnos(alumnos, validosAlumno);
    break;


    case 3:
        printf("Ingrese su numero de Matricula ---> ");
        scanf("%i", &matricula);
        printf("\n");

        mostrarAlumnoMatricula(alumnos, validosAlumno, matricula);
    break;


    case 4:
        ordenamientoXseleccion(alumnos, validosAlumno);
        mostrarAlumnos(alumnos, validosAlumno);
        printf("\n");
    break;


    case 5:
        printf("Seleccione el genero(M/F/O) ---> ");
        fflush(stdin);
        scanf("%c", &genero);
        printf("\n");

        mostrarAlumnosGenero(alumnos, validosAlumno, genero);
    break;


    case 6:

        ordenamientoXseleccion(alumnos, validosAlumno);
        mostrarAlumnos(alumnos, validosAlumno);

        newValidosAlumno = insertarNuevoAlumnoOrdenado(alumnos, validosAlumno);

        printf("\nTienes %i alumnos registrados\n \n", newValidosAlumno);

        mostrarAlumnos(alumnos, newValidosAlumno);

        printf("\n");
    break;


    case 7:

        ordenamientoXinsercion(alumnos, validosAlumno);

        mostrarAlumnos(alumnos, validosAlumno);

    break;


    case 8:

        printf("Seleccione el genero(M/F/O) ---> ");
        fflush(stdin);
        scanf("%c", &genero);
        printf("\n");

        contarAlumnosxGenero(alumnos, validosAlumno, genero);

    break;

    default:
    printf("El numero de ejercicion ingresado no es correcto. Por favor intente nuevamente... \n");
    printf("\n");
    break;
    }//FIN DEL SWITCH

     printf("Para volver al menu pulse 's' ---> ");
     fflush(stdin);
     scanf("%c", &eleccion);
     printf("\n");

     continuarMenu(eleccion);

    }while(eleccion == 's');
}
/*_____________________________________________________________________________________________________________________________________________________________________________________________________________*/

//Funciones del Menú

void mostrarMenu() {

    printf("1) Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario lo decida.\n");
    printf("\n");

    printf("2) Hacer una funcion que muestre un arreglo de alumnos por pantalla.\n");
    printf("\n");

    printf("3) Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo su matricula.\n");
    printf("\n");

    printf("4) Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de seleccion. El criterio de ordenacion es el numero de matricula.\n");
    printf("\n");

    printf("5) Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado (se envia por parametro).\n");
    printf("\n");

    printf("6) Hacer una funcion que inserte en un arreglo ordenado por matricula un nuevo dato, conservando el orden.\n");
    printf("\n");

    printf("7) Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de insercion. El criterio de ordenacion es el nombre.\n");
    printf("\n");

    printf("8) Hacer una funcion que cuente y retorne la cantidad de estudiantes de un genero determinado (se envia por parametro) que tiene un arreglo de alumnos.\n");
    printf("\n");
}

void continuarMenu(char eleccion) {

if(eleccion == 's') {

    mostrarMenu();
}
}
/*_____________________________________________________________________________________________________________________________________________________________________________________________________________*/

//Funciones de los Ejercicios:

/*1*/   int cargarAlumnosHasta(Alumno alumnos[DIMENSION]){

        int i = 0;
        char eleccion = 's';

        while(eleccion == 's' && i < DIMENSION) {

            alumnos[i] = cargaAlumno(); //En el arreglo en la posicion de i le cargamos un nuevo alumno

            printf("Pulse 's' para ingresar otro Alumno ---> ");
            fflush(stdin);
            scanf("%c", &eleccion);
            printf("\n");

            i++; }

        return i;
        }

/*1*/   Alumno cargaAlumno(){

        int numMatricula, numeroValido;
        int flag = 1;
        char generoAlum;


        Alumno nuevoAlumno; //Variable para cargar un alumno

        //Verificar si el tipo de dato ingresado por el usuario es correcto
        do {
            printf("Ingrese su numero de matricula  ---> ");
            fflush(stdin);

            numeroValido = scanf("%i", &numMatricula);

            if(numeroValido != 1) {
                printf("\nNo se ingreso un numero para indicar la matricula. Vuelve a intentarlo \n \n");
                flag = 0;
            }

        }while(numeroValido != 1);

        if(flag == 1) {
            nuevoAlumno.matricula = numMatricula;
        }
        printf("\n");

        //Fin verificación

        printf("Ingrese su nombre y apellido ---> ");
        fflush(stdin);
        gets(nuevoAlumno.nombre);
        printf("\n");

        //Verificación del genero

        do {

        printf("Ingrese su sexo (M/F/O) ---> ");
        fflush(stdin);
        scanf("%c", &generoAlum);

        if(generoAlum == 'f' || generoAlum == 'F') {
            nuevoAlumno.genero = generoAlum;
            flag = 1;
        }
        else if(generoAlum == 'm' || generoAlum == 'M'){
            nuevoAlumno.genero = generoAlum;
            flag = 1;
        }
        else if(generoAlum == 'o' || generoAlum == 'O') {
            nuevoAlumno.genero = generoAlum;
            flag = 1;
        }
        else {
            printf("\nGenero invalido. Vuelva a intentarlo");
            flag = 0;
        }
        }while(flag == 0);
        //Fin verificación del genero
        printf("\n");

        return nuevoAlumno; //Nos retorna ese alumno
        }

/*2*/   void mostrarAlumnos(Alumno alumnos[], int validosAlumno) {

        for(int i = 0; i < validosAlumno; i++) {

        mostrarAlumno(alumnos[i]);
            }
        }

/*2*/   void mostrarAlumno(Alumno mostrarAlum) { //Variable que me va a mostrar un alumno en específico

        printf("La Matricula del Alumno es: %i \n", mostrarAlum.matricula);
        printf("Nombre y Apellido del Alumno: %s \n", mostrarAlum.nombre);
        printf("Sexo del Alumno: %c \n", mostrarAlum.genero);
        printf("\n");
        }

/*3*/   void mostrarAlumnoMatricula(Alumno alumnos[], int validos, int matricula) {

        for(int i = 0; i < validos; i++) {

            if(alumnos[i].matricula == matricula) {

                mostrarAlumnoxMatricula(alumnos, i);
            }
            else {
                printf("La matricula no se encuentra en sistema... \n");
                printf("\n");
                }
            }
        }

/*3*/   void mostrarAlumnoxMatricula(Alumno alumnos[], int i) {

        printf("Nombre y Apellido del alumno es: %s \n", alumnos[i].nombre);
        printf("El genero es: %c \n", alumnos[i].genero);
        }

/*4*/   //Función Ordenamiento x Selección:
        void ordenamientoXseleccion(Alumno alumnos[], int validos) {

        int posmenor;
        Alumno aux;
        int i = 0;

        while (i < validos -1) {
            posmenor = posicionMenor(alumnos, i, validos);
            aux = alumnos[posmenor];
            alumnos[posmenor]=alumnos[i];
            alumnos[i]= aux;
            i++;
            }
        }
        //Función posición menor:
        int posicionMenor(Alumno alumnos[], int posicion, int validos) {

            Alumno menor = alumnos[posicion];
            int posmenor = posicion;
            int i = posicion +1;

            while (i < validos){

                if (menor.matricula > alumnos[i].matricula){
                    menor = alumnos[i];
                    posmenor = i; }

                i++; }
            return posmenor;
        }

/*5*/   void mostrarAlumnosGenero(Alumno alumnos[], int validos, char genero) {

        if(genero == 'f' || genero == 'F') {
            mostrarGenero(alumnos, validos, genero);
            }

        if(genero == 'm' || genero == 'M') {
            mostrarGenero(alumnos, validos, genero);
            }


        if(genero == 'o' || genero == 'O') {
            mostrarGenero(alumnos, validos, genero);
                }
        }

/*5*/   void mostrarGenero(Alumno alumnos[], int validos, char genero) {

        int i;

        if(genero == 'f' || genero == 'F') {

        printf("Mostrando alumnos del genero Femenino \n");
        printf("\n");

        for(i = 0; i < validos; i++) {

            if(alumnos[i].genero == genero) {

                printf("Nombre y Apellido ---> %s \n", alumnos[i].nombre);
                printf("Genero ---> %c (Femenino) \n", alumnos[i].genero);
                printf("Numero de Matricula ---> %i \n", alumnos[i].matricula);
                printf("\n");
            }
        }
        }
        if(genero == 'm'|| genero == 'M') {

                printf("Mostrando alumnos del genero Masculino \n");
                printf("\n");

            for(i = 0; i < validos; i++){

                if(alumnos[i].genero == genero) {

                printf("Nombre y Apellido ---> %s \n", alumnos[i].nombre);
                printf("Genero ---> %c (Masculino) \n", alumnos[i].genero);
                printf("Numero de Matricula ---> %i \n", alumnos[i].matricula);
                printf("\n");
                    }
                }
            }
        if(genero == 'o'|| genero == 'O') {

                printf("Mostrando alumnos de genero Indefinido \n");
                printf("\n");

            for(i = 0; i < validos; i++){

                if(alumnos[i].genero == genero) {

                printf("Nombre y Apellido ---> %s \n", alumnos[i].nombre);
                printf("Genero ---> %c (Indefinido) \n", alumnos[i].genero);
                printf("Numero de Matricula ---> %i \n", alumnos[i].matricula);
                printf("\n");
                        }
                    }
                }
            }

/*6*/   int insertarNuevoAlumnoOrdenado(Alumno alumnos[], int validos) {


        alumnos[validos] = cargaAlumno(); //Cargamos el nuevo alumno en un arreglo aparte para pisar Datos

        validos = validos + 1;

        ordenamientoXseleccion(alumnos, validos);

        return validos;
        }

///*7*/   //Función Ordenamiento x Inserción:

        void ordenamientoXinsercion(Alumno alumnos[], int validos) {

            int i = 0; //Indice actual

            while(i < validos - 1) {

                    insertar(alumnos, i, alumnos[i + 1]);
                    i++;
            }
        }

/*7*/   //Función que inserta el dato
        void insertar(Alumno alumnos[], int posicionBusqueda, Alumno alumnos1){ //Dato = dato a insertar

            int i = posicionBusqueda;

            while(i >= 0 && strcmp(alumnos1.nombre, alumnos[i].nombre) == 1) {

                alumnos[i + 1] = alumnos[i];
                i--;
            }
            alumnos[i + 1] = alumnos1;
        }

/*8*/   //Función que cuenta alumnos dependiendo el genero
        int contarAlumnosxGenero(Alumno alumnos[], int validos, char genero) {

        int i = 0;
        int cantAlumGenero;

        if(genero == 'f' || genero == 'F') {

            cantAlumGenero = contarxGenero(alumnos, validos, genero);
            printf("La cantidad de Alumnos con genero Femenino es de %i \n \n", cantAlumGenero);
            }

        if(genero == 'm' || genero == 'M') {

            cantAlumGenero = contarxGenero(alumnos, validos, genero);
            printf("La cantidad de Alumnos con genero Masculino es de %i \n \n", cantAlumGenero);
                }

        if(genero == 'o' || genero == 'O') {

            cantAlumGenero = contarxGenero(alumnos, validos, genero);
            printf("La cantidad de Alumnos con genero Indefinido es de %i \n \n", cantAlumGenero);
                }
            }

/*8*/   //Contar alumnos por genero
        int contarxGenero(Alumno alumnos[], int validos, char genero) {

        int i;
        int contGenero = 0;

        if(genero == 'f' || genero == 'F') {

            for(i = 0; i < validos; i++) {

            if(alumnos[i].genero == genero) {
                contGenero++;
                    }
                }
            }
        if(genero == 'm'|| genero == 'M') {

            for(i = 0; i < validos; i++){

            if(alumnos[i].genero == genero) {
                contGenero++;
                        }
                    }
                }
        if(genero == 'o'|| genero == 'O') {

            for(i = 0; i < validos; i++){

            if(alumnos[i].genero == genero) {
                contGenero++;
                    }
                }
            }

            return contGenero;
        }

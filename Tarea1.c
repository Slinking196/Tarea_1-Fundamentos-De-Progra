/*************** | Ejercicio Tarea 1 | *****************/
/* Autor: Matias Bugueño                               *
 * ICD1342 - Fundamentos de programación               *
 * 08 de Semptiembre del 2022                          */

/************************* | Análisis del problema | ****************************/
/* El problema consiste en mostrar al usuario como organizar conjunto de n      *
 * fotos indicados por el, para esto primero se debe verificar si el número     *
 * entregado nos permite realizar una piramide con la ayuda de los números      *
 * triangulares, si esto no se puede generar, entonces se verifica cuantos      *
 * marcos cuadrados se pueden generar con la mayor cantidad de fotos.           *
 *                                                                              *
 * Datos de Entrada:                                                            *
 *                                                                              *
 * - Un número el cual indica la cantidad de fotos que desea organizar el       *
 *   Usuario, si este ingresa el número 0 finaliza la ejecución del programa.   *
 *                                                                              *
 * Datos de salida:                                                             *   
 * - Se le indica al usuario si es que se puede realizar una piramide con       *
 *   la cantidad de fotos entregada, si es así, se le muestra al usuario la     *
 *   distribuición de las imagenes solo si la cantidad de la misma es menor o   *
 *   igual a 50.                                                                *
 * - Si el caso anterior no ocurre se le indica al usuario cuantos cuadrados    *
 *   perfectos se pueden formar con la cantidad de fotos ingresadas y si la     *
 *   cantidad de las mismas es menor o igual a 50 se le muestra la              *
 *   distribuición de las imagenes.                                             */

/********** | librerias | ************/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/************** | Función esTriangular() | ********************/
/* El proposito de esta función es verificar si el número     *
 * recibido es triangular o no.                               *
 * La entrada es el número que se desea verificar.            *
 * Si el número es triangular retorna la base del triangulo,  *
 * en caso contrario retorna -1                               */
size_t esTriangular(size_t numero) {
    //Declaración de variables
    size_t n = 1; //Variable que aumentará en el bucle
    size_t resultado;

    // Proceso
    while (true) {
        resultado = n * (n + 1) / 2;
        if (resultado == numero) return n;
        if (resultado > numero) break;
        n++;
    }
    
    return -1;
}


/**************** | Función graficarTriangulo() |  ******************/
/* El proposito de esta función es mostrar al usuario como          *
 * quedaría un conjunto de fotos dibujadas como una piramide.       *
 * La entrada serán la cantidad de fotos a colocar y la base de la  *
 * piramide.                                                        *
 * No retorna valores.                                              */
void graficarTriangulo(size_t numero, size_t basePiramide) {
    // Declaración de variables
    size_t i, j;          //Variables para bucles
    size_t baseAux = 1;
    
    // Proceso
    while (basePiramide > 0) {
        for (i = 0; i < basePiramide - 1; i++) {
            printf(" ");
        }
        for (j = 0; j < baseAux; j++) {
            printf("F ");
        }
        printf("\n");
        baseAux++;
        basePiramide--;
    }
}


/***************** | Función contCuadrados() | *******************/
/* El proposito de esta función es contar la cantidad de         *
 * cuadrados perfectos que se pueden encontrar dentro del número *
 * recibido.                                                     *
 * Entrada: Un número para llevar a cabo los calculos.           *
 * Retorna la cantidad de cuadrados perfectos.                   */
size_t contCuadrados(size_t numero) {
    // Declaración de variables
    size_t cont = 0;
    
    // Proceso
    while (numero > 0) {
        cont++;
        
        numero = numero - ((size_t)sqrt(numero) * (size_t)sqrt(numero));
    }
    
    return cont;
}


/******************* | Función graficarCuadrados() | *************************/
/* El proposito de esta función es mostrar al usuario la distribución de     *
 * todas las fotos para generar cuadrados perfectos de distinto tamaño.      *
 * La entrada son la cantidad de fotos.                                      *
 * No retorna valores.                                                       */
void graficarCuadrados(size_t fotos) {
    // Declaración de variables
    size_t i,j;           //Variables para bucles
    size_t baseCuadrado;
    
    // Proceso
    while (fotos > 0) {
        baseCuadrado = (size_t) sqrt(fotos);
        fotos = fotos - (size_t) pow(baseCuadrado, 2);
        
        for (i = 0; i < baseCuadrado; i++) {
            for (j = 0; j < baseCuadrado; j++) {
                printf("F ");
            }
            printf("\n");
        }
    }
}


int main() {
    // Definición de variables
    size_t cantFotos, auxCantFotos;
    size_t basePiramide;
    size_t baseCuadrado;
    size_t cantCuadrados;
    size_t areaMarco;
    size_t cont = 0;
    
    // Proceso
    while (true) {
        scanf("%zd", &cantFotos);
        if (cantFotos == 0) break;
        auxCantFotos = cantFotos;
        cont++;
        
        printf("----------------------------------------------------------------------------\n");
        printf("CASO DE PRUEBA #%zd - CANTIDAD DE FOTOS %zd\n", cont, cantFotos);
        printf("----------------------------------------------------------------------------\n");
        
        basePiramide = esTriangular(cantFotos);
        if (basePiramide != -1) {
            printf("Sophie formará un triángulo de lado %zd con %zd foto(s)\n\n", basePiramide, cantFotos);
            if (cantFotos <= 50) {
                printf("Como la cantidad de fotos es menor o igual a 50, se diagrama!\n");
                graficarTriangulo(cantFotos, basePiramide);
                printf("\n");
            }
        }
        else {
            cantCuadrados = contCuadrados(cantFotos);
            if (cantCuadrados != 1) printf("Sophie formará %zd cuadrados con %zd foto(s) :\n", cantCuadrados, cantFotos);
            
            while (true){
                if (auxCantFotos == 0) break;
                
                baseCuadrado = (size_t) sqrt(auxCantFotos);
                areaMarco = (size_t)sqrt(auxCantFotos) * (size_t)sqrt(auxCantFotos);
                auxCantFotos = auxCantFotos - areaMarco;
                
                if (cantCuadrados != 1) {
                    printf("Un cuadrado de lado %zd - (%zd fotos)\n", baseCuadrado, areaMarco);
                }
                else {
                    printf("Sophie formará un cuadrado de lado %zd con %zd foto(s)\n\n", baseCuadrado, cantFotos);
                }
                    
            }
            if (cantFotos <= 50) {
                printf("Como la cantidad de fotos es menor o igual a 50, se diagrama!\n");
                graficarCuadrados(cantFotos);
                printf("\n");
            }
        }
        printf("\n");
    }
    
    printf("***** FIN PROCESAMIENTO DE DATOS *****");
    return 0;
}

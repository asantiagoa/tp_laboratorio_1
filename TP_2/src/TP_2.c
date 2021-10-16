#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "funciones.h"



int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    Employee lista[TAM];

    menuEmployee(lista,
                 "\nEntrada invalida.",
                 "\nIngrese opcion:     \n1-ALTA    2-MODIFICACION    \n3-BAJA     4-LISTA \n ",
                 's',
                 'n',
                 "\nDesea continuar? (s/n): ",
                 "Ingrese el nombre del empleado: ",
                 "Ingrese el apellido del empleado: ",
                 "Ingrese el salario del empleado: ",
                 "Ingrese el sector al que pertecene el empleado(RRHH - 100 | VENTAS - 101 | TECNICO - 102): ",
                 "Ingrese el ID del empleado: ",
                 "\nIngrese opcion:     \n1-Modificar nombre    2-Modificar Apellido    \n3-Modificar Salario     4-Modificar Sector \n ",
                 "\nIngrese opcion:     \n1-Listar Alfabeticamente     2-Listar por sector",
				 "Error. Primero debe ingresar un empleado.",
				 "Ingrese el orden en el que se desea ordenar: \n0-Creciente	1-Decreciente");



    return 0;
}

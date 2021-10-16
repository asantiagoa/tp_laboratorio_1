#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "funciones.h"





int initEmployees(Employee* list, int len)
{
    int i;
    int status = -1;

    for(i=0; i<len ; i++)
    {
        list[i].isEmpty = 0;
        status = 0;
    }
    return status;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)//god why
{
    int i;
    int ret;

    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;

            list[i].isEmpty = 1;
            ret = 0;

            break;
        }
        else if(list[len].isEmpty != 0)
        {
            printf("NO SPACE");
            ret = -1;
        }
    }
    return ret;
}

int getNextId(Employee* list, int len)
{
    int id=0;
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            id = i + IDBASE;
            break;
        }
    }

    return id;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index;
    int i;

    for(i = 0; i < len; i++)
    {
        if(list[i].id == id)
        {
            index = i;
        }
    }

    /*index = id - IDBASE;
    if((id < IDBASE) || (id > (IDBASE + len)) || list[index].isEmpty == 0)
    {
        index = -1;
    }*/

    return index;
}

int removeEmployee(Employee* list, int len, int id)
{
    int ret = 0;

    if(id == -1)
    {
        ret = -1;
    }
    else
    {
        list[id].isEmpty = 0;
    }

    return ret;

}

int sortEmployees(Employee* list, int len, int order)//by last name
{
    int ret=0;
    int i,j;
    Employee aux;

    for(i = 0; i < len; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(list[i].isEmpty == 1)
            {
                if(order == 1 && strcmp(list[i].lastName, list[j].lastName)<0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else if(order == 0 &&  strcmp(list[i].lastName, list[j].lastName)>0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    return ret;
}

int sortEmployeesBySector(Employee* list, int len, int order)
{
    int ret=0;
    int i,j;
    Employee aux;

    for(i = 0; i < len; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(list[i].isEmpty == 1)
            {
                if(order == 1 && (list[i].sector < list[j].sector))
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else if(order == 0 &&  (list[i].sector > list[j].sector))
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    return ret;
}

int printEmployees(Employee* list, int length)
{
    int i;

    printf("ID              NAME            LAST NAME          SALARY              SECTOR\n");

    for(i = 0; i < length; i++)
    {
        if(list[i].isEmpty == 1)
        {
            printf("%d  %14s  %16s  %16.2f  %16d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            fflush(stdin);
        }
    }

    return 0;
}


void menuEmployee(Employee* lista, char invalidEntry[], char optionMsg[], char continueChar, char continueNeg, char continueMsg[],
                  char namePrompt[], char lnamePrompt[], char salaryPrompt[], char sectorPrompt[], char idPrompt[], char modifyMsg[],
                  char informPrompt[], char noEmployeeError[], char orderPrompt[])
{
    int opcion;
    int ord;
    int inputId;
    int arrayId;

    int flagEmployee=0;

    char auxName[TNME];
    char auxLName[TNME];

    char seguir = 's';


    do
    {

    opcion = ingresarEntero(optionMsg);
    fflush(stdin);


    switch(opcion)
    {
    case 1://alta

        ingresarString(auxName, namePrompt, invalidEntry, TNME);
        ingresarString(auxLName, lnamePrompt, invalidEntry, TNME);
        addEmployee(lista, TAM,
                        getNextId(lista, TAM),
                        auxName,
                        auxLName,
                        ingresarFloatPos(salaryPrompt, invalidEntry),
                        ingresarEnteroLim(sectorPrompt, invalidEntry, RRHH, TECNICO));
        flagEmployee = 1;
        break;


    case 2://modificar

    	if(flagEmployee == 1)
    	{
			inputId = ingresarEntero(idPrompt);
			arrayId = findEmployeeById(lista, TAM, inputId);
			printf("%d", arrayId);


			while(arrayId == -1)
			{
				printf("%s", invalidEntry);
				inputId = ingresarEntero(idPrompt);
				arrayId = findEmployeeById(lista, TAM, inputId);

			}

			opcion = ingresarEntero(modifyMsg);

			switch(opcion)
			{
				case 1://mod nombre
					ingresarString(auxName, namePrompt, invalidEntry, TNME);
					strcpy(lista[arrayId].name, auxName);
					printf("%s",lista[arrayId].name);
					break;

				case 2://mod apellido
					ingresarString(auxLName, namePrompt, invalidEntry, TNME);
					strcpy(lista[arrayId].lastName, auxLName);
					break;

				case 3://mod salario
					lista[arrayId].salary = ingresarFloatPos(salaryPrompt, invalidEntry);
					break;

				case 4://mod sector
					lista[arrayId].sector = ingresarEnteroLim(sectorPrompt, invalidEntry, RRHH, TECNICO);
					break;

				default:
					printf("%s" ,invalidEntry);


			}
    	}
		else
		{
			printf(noEmployeeError);
		}
		break;



    case 3://baja
    	if(flagEmployee == 1)
    	{
        inputId = ingresarEntero(idPrompt);
        arrayId = findEmployeeById(lista, TAM, inputId);

        /*while(arrayId == -1)
        {
            printf("%s", invalidEntry);
            inputId = ingresarEntero(idPrompt);
            arrayId = findEmployeeById(lista, TAM, inputId);

        }*/
        removeEmployee(lista, TAM, arrayId);
    	}
		else
		{
			printf(noEmployeeError);
		}
		break;


    case 4://informar
    	if(flagEmployee == 1)
    	{
        opcion = ingresarEntero(informPrompt);

			switch(opcion)
			{
			case 1:
				ord = ingresarEntero(orderPrompt);
				sortEmployees(lista, TAM, ord);
				printEmployees(lista, TAM);
				break;

			case 2:
				ord = ingresarEntero(orderPrompt);
				sortEmployeesBySector(lista, TAM, ord);
				printEmployees(lista, TAM);
				break;
			}
    	}
		else
		{
			printf(noEmployeeError);
		}
		break;


     default:
        printf("%s" ,invalidEntry);
        break;

    }
    seguir = continuarMenu(continueMsg, invalidEntry, continueChar, continueNeg);
    }while(seguir==continueChar);
}



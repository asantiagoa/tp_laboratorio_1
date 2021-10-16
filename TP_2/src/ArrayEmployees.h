#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define TAM 1000
#define TNME 51
#define NAMSZE 51
#define IDBASE 1000

#define RRHH 100
#define VENTA 101
#define TECNICO 102



struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;



int initEmployees(Employee* list, int len);/** \brief To indicate that all position in the array are empty,
                                            * this function put the flag (isEmpty) in TRUE in all
                                            * position of the array
                                            * \param list Employee* Pointer to array of employees
                                            * \param len int Array length
                                            * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
                                            *
                                            */


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);/** \brief add in a existing list of employees the values received as parameters
                                                                                                    * in the first empty position
                                                                                                    * \param list employee*
                                                                                                    * \param len int
                                                                                                    * \param id int
                                                                                                    * \param name[] char
                                                                                                    * \param lastName[] char
                                                                                                    * \param salary float
                                                                                                    * \param sector int
                                                                                                    * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
                                                                                                    */



int findEmployeeById(Employee* list, int len,int id);/** \brief find an Employee by Id en returns the index position in array.
                                                    *
                                                    * \param list Employee*
                                                    * \param len int
                                                    * \param id int
                                                    * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
                                                    */


int removeEmployee(Employee* list, int len, int id);/** \brief Remove an Employee by Id (put isEmpty Flag in 1)
                                                    *
                                                    * \param list Employee*
                                                    * \param len int
                                                    * \param id int
                                                    * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
                                                    */


int sortEmployees(Employee* list, int len, int order);/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
                                                        * \param list Employee*
                                                        * \param len int
                                                        * \param order int [1] indicate UP - [0] indicate DOWN
                                                        * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
                                                        */

int sortEmployeesBySector(Employee* list, int len, int order);


int printEmployees(Employee* list, int length);/** \brief print the content of employees array
                                                * \param list Employee*
                                                * \param length int
                                                * \return int
                                                */

int getNextId(Employee* list, int len);/** \brief determines the id of the next employee added to the array as position on the array + constant IDBASE
                                        * \param list Employee*
                                        * \param len int
                                        * \return int return
                                        */

void menuEmployee(Employee* lista, char invalidEntry[], char optionMsg[], char continueChar, char continueNeg, char continueMsg[],
                  char namePrompt[], char lnamePrompt[], char salaryPrompt[], char sectorPrompt[], char idPrompt[], char modifyMsg[],
                  char informPrompt[], char noEmployeeError[], char orderPrompt[]);

#endif // ARRAYEMPLOYEES_H_INCLUDED

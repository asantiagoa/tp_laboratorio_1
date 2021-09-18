#include <stdio.h>
#include <stdlib.h>
#include "libCalc.h"
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    float num1, num2;
    num1 = 0;
    num2 = 0;
    float resSum, resRest, resMult, resDiv;
    int resFact1, resFact2;
    int flag;
    flag = 0;
    int switchControl;

    do
    {
        printf("Ingrese el numero correspondiente a la operacion que desea realizar\n1: Ingresar primer operando(%.2f)          2: Ingresar segundo operando(%.2f)\n3: Calcular todas las operaciones          4: Mostrar resultados\n5: Salir\n",num1, num2);
        fflush(stdin);
        scanf("%d",&switchControl);
        printf("\n");
        switch(switchControl)
        {

            case 1:
            {
                fflush(stdin);
                printf("ingrese el primer operando: ");
                scanf("%f",&num1);
                printf("\n");
                break;
            }

            case 2:
            {
                fflush(stdin);
                printf("ingrese el segundo operando: ");
                scanf("%f",&num2);
                printf("\n");
                break;
            }

            case 3:
            {
                flag=1;
                resSum = calcSum(num1, num2);
                resRest = calcRes(num1, num2);
                resMult = calcMult(num1, num2);
                resDiv = calcDiv(num1, num2);
                resFact1 = calcFact(num1);
                resFact2 = calcFact(num2);

                break;
            }

            case 4:
            {
                if (flag==1)//solo se ejecuta si se calculo antes.
                {
                	system("cls");
                    printf("el resultado de la suma entre %.2f y %.2f es: %.2f\n",num1 ,num2 ,resSum);
                    printf("el resultado de la resta entre %.2f y %.2f es: %.2f\n",num1 ,num2 ,resRest);
                    printf("el resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n",num1 ,num2 ,resMult);
                    if (num2 == 0)
                    {
                        printf("no se puede dividir por 0\n");
                    }
                    else
                    {
                        printf("el cociente de la division entre %.2f y %.2f es: %.2f\n",num1 ,num2 ,resDiv);
                    }


                    if (num1<1 && num2>=1)
                    {
                        printf("el factorial de %.0f no puede conseguirse porque es un numero negativo, y el factorial de %0.f es: %d\n\n\n",num1, num2, resFact2);
                    }
                    else if (num1>=1 && num2<1)
                    {
                        printf("el factorial de %.0f es: %d, y el factorial de %0.f no puede conseguirse porque es un numero negativo\n\n\n",num1, resFact1, num2);
                    }
                    else if (num1<1 && num2<1)
                    {
                        printf("no puede conseguirse ningun factorial porque los dos numeros son negativos\n\n\n");
                    }
                    else
                    {
                        printf("el factorial de %d es: %d, y el factorial de %d es: %d\n\n\n",(int)num1, resFact1, (int)num2, resFact2);
                    }
                }
                else
                {
                    printf("error, debe realizar los calculos antes de mostrar los resultados.\n\n");
                }
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                fflush(stdin);
                printf("entrada invalida\n");
                break;
            }

        }
    }while(switchControl!=5);
    return 0;
}

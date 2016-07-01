/* 
 * File:   main.c
 * Author: juanmiguel
 *
 * Created on 23 de junio de 2016, 20:13
 */
#include <stdio.h>
#define tamanio 10

/*
 * 
 */
main()
{
    float A[tamanio][tamanio];
    //float A[3][3] = { {10, 1, 2}, {2, 15, 3}, {2, 3, 20} };
    float X[tamanio];
    float b[tamanio];
    //float b[3] = {100, 150, 120};
    float Ej[tamanio][tamanio];
    float Cj[tamanio];
    float X0[tamanio] = {0, 0, 0};
    float X1[tamanio] = {0, 0, 0};
    float cota = 1;
    float tolerancia = 0.00007; 
    float mayor = 1;
    int dimension;
    
    int i;
    int j;
    int k;
    int l = 0;    
    
    // PIDE LA DIMENSION DE LA MATRIZ
    printf("\nIngrese la dimensión de A \n");
    scanf("%d",&dimension);
    
    // PIDE LOS VALORES DE LA MATRIZ
    printf("\nIngrese uno a uno de iz a der los valores de A \n");
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            scanf("%f" ,&A[i][j]);
        }
        
    }    
    // IMPRIME LA MATRIZ INGRESADA
    printf("\nEsta es la matriz ingresada\n");
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("%.1f " ,A[i][j]);
        }
        printf("\n");
    }

    // PIDE LOS VALORES DE b
    printf("\nIngrese uno a uno los valores de b \n");
    for(i = 0; i < dimension; i++)
    {
        scanf("%f" ,&b[i]);       
    }   
    
    // IMPRIME b INGRESADb
    printf("\nEsta es b ingresado\n");
    for(i = 0; i < dimension; i++)
    {       
        printf("%.1f " ,b[i]);
        printf("\n");
    }
    
    // CALCULA Cj
    for(i = 0; i < dimension; i++)
    {       
        Cj[i] = b[i] / A[i][i];
    }
    
    // IMPRIME el Cj calculado
    printf("\nEsto es Cj\n");
    for(i = 0; i < dimension; i++)
    {       
        printf("%.1f " ,Cj[i]);
        printf("\n");
    }
    
    // CALCULA Ej
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            if(i == j)
            {
                Ej[i][j] = 0;
            }
            else
            {
                Ej[i][j] = - (A[i][j] / A[i][i]);
            }
        }
    }
    
    // IMPRIME el Ej calculado
    printf("\nEsto es Ej Calculado\n");
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("%.4f " ,Ej[i][j]);
        }
        printf("\n");
    }
    
    // IMPRIME X0
    printf("\nEsto es la semilla\n");
    for(i = 0; i < dimension; i++)
    {       
        printf("%.1f " ,X0[i]);
        printf("\n");
    }

    // HACE EL METODO DE JACOBI
    while (mayor > tolerancia)
    {
        for(i = 0; i < dimension; i++)
        {
            for (j = 0; j < dimension; j++)
            {
                X1[i] = X1[i] + (Ej[i][j] * X0[j]);            
            }
            X1[i] = X1[i] + Cj[i];
        }
        
        printf("\nX%d =\n",l);
        for(i = 0; i < dimension; i++)
        {       
            printf("%.7f " ,X1[i]);
            printf("\n");
        }
        
        // ELIJE EL MAYOR DE X1
        //mayor = X1[0] - X0[0];
        mayor = fabs(X1[0] - X0[0]);
        //printf("\n1 mayor %.7f\n",fabs(mayor));

        for(i = 0; i < dimension; i++)
        {   
            if (fabs(X1[i] - X0[i]) > mayor)
            {
                mayor = fabs(X1[i] - X0[i]);
            }
        }
        
        printf("\nmayor %.7f\n",mayor);
        
        // IGUALO X1 a X0 Y BORRO X1
        for(i = 0; i < dimension; i++)
        {
            X0[i] = X1[i];
        }        
        //limpio X1 
        for(i = 0; i < dimension; i++)
        {
            X1[i] = 0;
        }
        l++;
    }
    /*
    // CALCULO X1
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            X1[i] = X1[i] + (Ej[i][j] * X0[j]);            
        }
        X1[i] = X1[i] + Cj[i];
    }
        
    //IMPRIME X1
    printf("\nEsto es la X1\n");

    for(i = 0; i < dimension; i++)
    {       
        printf("%.3f " ,X1[i]);
        printf("\n");
    }

    // IGUALO X1 a X0 Y BORRO X1
    for(i = 0; i < dimension; i++)
    {
        X0[i] = X1[i];
        X1[i] = 0;
    }
    
    
    X1[0] = 0;
    X1[1] = 0;
    X1[2] = 0;
    
    // CALCULO X1
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            X1[i] = X1[i] + (Ej[i][j] * X0[j]);            
        }
        X1[i] = X1[i] + Cj[i];
    }
        
    //IMPRIME X1
    printf("\nEsto es la X2\n");

    for(i = 0; i < dimension; i++)
    {       
        printf("%.3f " ,X1[i]);
        printf("\n");
    }
    */    
    return (0);
}


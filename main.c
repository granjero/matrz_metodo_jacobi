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
    int dimension; //recibe la dimension de la matriz
    float A[tamanio][tamanio];
    float X[tamanio];
    float b[tamanio];
    float Ej[tamanio][tamanio];
    float Cj[tamanio];
    float X0[tamanio];
    float X1[tamanio];
    float tolerancia = 0.00001; 
    float Difx1x0 = 1;
    
    int i; //CONTADOR PARA BUCLES
    int j; //CONTADOR PARA BULCES
    int l = 0; // CONTADOR DE ITERACIONES DE JACOBI
    int m = 0; // CONTADOR PARA ARMAR LAS MATRICES DEL ARCHIVO
        
    FILE *valoresMatriz; //VARIABLE FILE PARA EL ARCHIVO
  
    valoresMatriz = fopen("datos.txt", "r+"); // ABRE EL ARCHIVO EN VALORESmATRIZ
    
    //ITERA HASTA EL FINAL DEL ARCHIVO
    while(!feof(valoresMatriz))
    {
        if (m == 0) // TOMA LA DIMENSION QUE ES EL PRIMER DATO DEL ARCHIVO
        {
            fscanf(valoresMatriz, "%d", &dimension); //guarda en dimension el primer valor del archivo
            m++;
        }
        
        if (m < (dimension * dimension)) //ENTRA CUANDO M ES MENOR QUE LA CANTIDAD DE ELEMENTO DE LA MATRIZ
        {
            //DOS FOR ENCADENADOS PARA ARMAR LA MATRIZ FILA POR FILA
            for(i = 0; i < dimension; i++)
            {
                for (j = 0; j < dimension; j++)
                {
                    fscanf(valoresMatriz, "%f", &A[i][j]);
                    m++;
                }
            }
        }
        
        if(m > dimension * dimension) //ENTRA CUANDO M ES MAYOR A 
        {
            for (i = 0; i < dimension; i++)
            {
                fscanf(valoresMatriz, "%f", &b[i]);
                m++;
            }
        }
    }    
        
    //asigna X0 y X1 en 0
    for(i = 0; i < dimension; i++)
    {       
        X0[i] = 0;
        X1[i] = 0;
    }
    
    //IMPRIME LA DIMENSION LEIDA DEL ARCHIVO
    printf("dimension = %d", dimension);

    // IMPRIME LA MATRIZ LEIDA DEL ARCHIVO
    printf("\nEsta es la matriz\n");
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            printf("%.1f " ,A[i][j]);
        }
        printf("\n");
    }

    // IMPRIME b LEIDO DEL ARCHIVO 
    printf("\nEsta es b \n");
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
    while (Difx1x0 > tolerancia)
    {
        for(i = 0; i < dimension; i++)
        {
            for (j = 0; j < dimension; j++)
            {
                X1[i] = X1[i] + (Ej[i][j] * X0[j]);            
            }
            X1[i] = X1[i] + Cj[i];
        }
        
        printf("\nX%d\n",l);
        for(i = 0; i < dimension; i++)
        {       
            printf("%.7f " ,X1[i]);
            printf("\n");
        }
        
        // ELIJE LA DIFERENCIA MAYOR DE X1
        Difx1x0 = fabs(X1[0] - X0[0]);

        for(i = 0; i < dimension; i++)
        {   
            if (fabs(X1[i] - X0[i]) > Difx1x0)
            {
                Difx1x0 = fabs(X1[i] - X0[i]);
            }
        }
        
        printf("\n\n%d Diferencia entre X1 y X0 = %f\n",l + 1, Difx1x0);
        
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
    return (0);
}
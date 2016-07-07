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
    int dimension; //recibe la dimension
    //float A[tamanio][tamanio];
    float A[tamanio][tamanio] = { {120, 11, 12}, {12, 125, 13}, {12, 13, 240} };
    float X[tamanio];
    //float b[tamanio];
    float b[tamanio] = {100, 150, 120};
    float Ej[tamanio][tamanio];
    float Cj[tamanio];
    float X0[tamanio] = {0, 0, 0};
    float X1[tamanio] = {0, 0, 0};
    float tolerancia = 0.00007; 
    float Difx1x0 = 1;
    
    int i;
    int j;
    int k;
    int l = 0;  
    int m = 0;
    
    FILE *valoresMatriz;    

    
    // PIDE LA DIMENSION DE LA MATRIZ
    //printf("\nIngrese la dimensión de A \n");
    //scanf("%d",&dimension);
    
    // PIDE LOS VALORES DE LA MATRIZ
/*
    printf("\nIngrese uno a uno de iz a der los valores de A \n");
    for(i = 0; i < dimension; i++)
    {
        for (j = 0; j < dimension; j++)
        {
            scanf("%f" ,&A[i][j]);
        }
        
    }    
    */
    
    valoresMatriz = fopen("datos.txt", "r+");
    i = 0;
    
    while(!feof(valoresMatriz))
    {
        if (m == 0)
        {
            fscanf(valoresMatriz, "%d", &dimension);
            m++;
            printf("dimension2 = %d", dimension);
        }
        
        
        
        if (m < (dimension * dimension))
        {
            
            for(i = 0; i < dimension; i++)
            {
                for (j = 0; j < dimension; j++)
                {
                    fscanf(valoresMatriz, "%f", &A[i][j]);
                    m++;
                }
            }
        }
        
        if(m > dimension * dimension)
        {
            for (i = 0; i < dimension; i++)
                {
                    fscanf(valoresMatriz, "%f", &b[i]);
                    m++;
                }
        }
        
        //fscanf(valoresMatriz, "%f", &variable);
        
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
/*
    printf("\nIngrese uno a uno los valores de b \n");
    for(i = 0; i < dimension; i++)
    {
        scanf("%f" ,&b[i]);       
    }   
    
*/
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
        
        // ELIJE EL MAYOR DE X1
        //Difx1x0 = X1[0] - X0[0];
        Difx1x0 = fabs(X1[0] - X0[0]);
        //printf("\n1 Difx1x0 %.7f\n",fabs(Difx1x0));

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


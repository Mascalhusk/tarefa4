#include<stdio.h>
#include<stdlib.h>

void ler(double **M, int dim, FILE*leitura)
{	int i, j;
        double a;	 

	for (i=0; i<dim; i++) 
	{
	 	M[i] = malloc((dim+1)*sizeof(double));	
	}
	 
	i = j = 0;
	while(fscanf(leitura, "%lf", &a) != EOF) 
	{
		M[i][j] = a;
	 	j++;
	 	if(j==dim+1) 
	 	{	j=0; i++;	}
	
	}

}

void imprime(double **M, int dim)
{	int i, j;

	for (i=0; i<dim; i++ )
   	{	 for ( j=0; j<dim+1; j++ )
    		{
       			printf ("%lf \t", M[ i ][ j ]);
    		}
		printf("\n\n");	
 	}
 	
}

void decomposicaoLU(double **M, int dim)
{	double **L, **U;
	int i,j,k;
	float soma1, soma2;
   
	L = malloc( dim*sizeof(double*));
	U = malloc( dim*sizeof(double*));
     
     
    	for(i=0;i<dim;i++)
    	{  	
		L[i] = malloc((dim+1)*sizeof(double));	
       		L[i][0] = M[i][0];
    	}
    
    	for(i=0;i<dim;i++)
    	{	for(j=0;j<dim;j++)
    	 	{	
			U[i] = malloc((dim+1)*sizeof(double));	
    	      		
			if(i==j)
    	 	  	{  U[i][i] = 1;
    	 	  	}
    	      		else
    	      		{   
				U[0][j] = M[i][j]/L[0][0];
   	     		}    
    	 	}
    	}
    
	for(i=1;i<dim;i++)
	{	for(j=1;j<dim;j++)
    		{		 
    	        	for(k=0;k<j-1;k++)
    	        	{   	soma1 = soma1 + U[i][k]*L[k][i];
    	            		soma2 = soma2 + U[k][i]*L[i][k];
    	        	}
    	        	
			L[i][j] = M[i][j] - soma1;
    	  
		}
    	  
		for(j=i+1;j<dim;j++)
 	   	{     
		   	U[i][j] = (M[i][j] - soma2)/L[i][i];
    	  	}
   	}
	
	printf ("\nA matriz L é:\n");
	imprime(L, dim);
	printf ("\nA matriz U é:\n");
	imprime(U, dim);
}

void escalonamento(double **M, int dim)
{
	int i, j, k;
	double pivo;
	
	for(k=0; k<dim-1; v++)
	{
		for(i=k+1; i<dim; i++)
		{
			pivo = (M[i][k] / M[k][k]);

			for(j=k; j<dim+1; j++)
				M[i][j] = M[i][j] - (pivo * M[k][j]);
		}	
	}
	
}

int main()
{	
	int i, j, dim;
	double **M,a;
	FILE *leitura;

	leitura = fopen("matriz.dat","r");
	i = fscanf(leitura, "%d", &dim);
	M = malloc(dim*sizeof(double *));
        
        ler(M,dim,leitura);
	printf ("\nA matriz fornecida é:\n");
	imprime(M, dim);

 	escalonamento( M, dim);
	printf ("\nA matriz após o escalonamento é:\n");
	imprime(M, dim);

	decomposicaoLU( M, dim);

}

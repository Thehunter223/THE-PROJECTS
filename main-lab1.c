#include <stdio.h>
#include <stdlib.h>
#define dA(I,J) (*(dA +(I)*c + (J)))
#define dB(I,J) (*(dB +(I)*c + (J)))
#define dC(I,J) (*(dC +(I)*c + (J)))

void mat_add(int m,int n,double *A,double *B,double *C);
void mat_mlt(int m,int n,int p,double *A,double *B,double *C);
void mat_trnsps(int m,int n,double *A,double *B);
void is_mat_equal(int m,int n,double *A,double *B);
int main() {
	
	int operations=1;
		
	int r,c,p;
	double *dA;
	double *dB,*dC;

	int i,j;
	
	while(operations != 0){
		printf("Choose operation to proceed: \n1.Matrix addition\n2.Matrix multiplication\n3.Matrix transpose\n4.Symmetric matrix control\n");
		scanf("%d",&operations);
		
		switch(operations){
			case 1:
				printf("Number of rows of the first matrix: \n");
				scanf("%d",&r);
	
				printf("Number of column of the first matrix: \n");
				scanf("%d",&c);
				dA=(double *)malloc(r*c*sizeof(double));
				printf("\nEnter the first matrix: \n");
				
				for(i=0;i<r;i++)
				for(j=0;j<c;j++)
				scanf("%lf",&dA(i,j));
				
				dB=(double *)malloc(r*c*sizeof(double));
				
				printf("Enter the second matrix: \n");
				for(i=0;i<r;i++)
				for(j=0;j<c;j++)
				scanf("%lf",&dB(i,j));
				
				dC=(double *)malloc(r*c*sizeof(double));
				
				mat_add(r,c,dA,dB,dC);
				free(dA);
				free(dB);
				free(dC);
				break;
			case 2:
				printf("Number of rows of the first matrix: \n");
				scanf("%d",&r);
	
				printf("Number of column of the first matrix: \n");
				scanf("%d",&c);
				dA=(double *)malloc(r*c*sizeof(double));
				printf("\nEnter the first matrix: \n");
				
				for(i=0;i<r;i++)
				for(j=0;j<c;j++)
				scanf("%lf",&dA(i,j));
				
				dB=(double *)malloc(r*c*sizeof(double));
				
				printf("Enter the column of the second matrix: \n");
				scanf("%d",&p);
				
				printf("Enter the second matrix: \n");
				for(i=0;i<c;i++)
				for(j=0;j<p;j++)
				scanf("%lf",&dB(i,j));
				
				dC=(double *)malloc(r*c*sizeof(double));
				mat_mlt(r,c,p,dA,dB,dC);				
				free(dA);
				free(dB);
				free(dC);
				break;
			case 3:
				printf("Number of rows of the first matrix: \n");
				scanf("%d",&r);
	
				printf("Number of column of the first matrix: \n");
				scanf("%d",&c);
				dA=(double *)malloc(r*c*sizeof(double));
				printf("\nEnter the first matrix: \n");
			
				for(i=0;i<r;i++)
				for(j=0;j<c;j++)
				scanf("%lf",&dA(i,j));
				
				dB=(double *)malloc(r*c*sizeof(double));
				
				mat_trnsps(r,c,dA,dB);
				free(dA);
				free(dB);
				break;
			case 4:
				printf("Number of rows of the first matrix: \n");
				scanf("%d",&r);
	
				printf("Number of column of the first matrix: \n");
				scanf("%d",&c);
				dA=(double *)malloc(r*c*sizeof(double));
				printf("\nEnter the first matrix: \n");
			
				for(i=0;i<r;i++)
				for(j=0;j<c;j++)
				scanf("%lf",&dA(i,j));
				
				dB=(double *)malloc(r*c*sizeof(double));			
				is_mat_equal(r,c,dA,dB);
				free(dA);
				free(dB);
				break;	
		}
	}
	
	return 1;
}

#define A(I,J) (*(A +(I)*n + (J)))

void mat_display(int m,int n,double *A){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
		printf("%f ",A(i,j));	
		printf("\n");
	}
	
}
#undef A

#define A(I,J) (*(A +(I)*n + (J)))
#define B(I,J) (*(B +(I)*n + (J)))
#define C(I,J) (*(C +(I)*n + (J)))

void mat_add(int m,int n,double *A,double *B,double *C){
	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			C(i,j)=A(i,j)+B(i,j);
		}
	}
	mat_display(m,n,C);
}

void mat_mlt(int m,int n,int p,double *A,double *B,double *C){
	int i,j,k;
	for(i=0;i<m;i++){
		for(j=0;j<p;j++){
			for(k=0;k<n;k++){
				C(i,j)+=A(i,k)*B(k,j);
			}
		}
	}
	mat_display(m,p,C);
}

void mat_trnsps(int m,int n,double *A,double *B){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			B(j,i)=A(i,j);
		}
	}
	
	mat_display(n,m,B);
}

void is_mat_equal(int m,int n,double *A,double *B){
	int i,j;
	int control=0;
	mat_trnsps(m,n,A,B);
	printf("\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i != j){
				if(A(i,j)==B(i,j)){
					control=1;
				}
			}
		}
	}
	
	if(control == 1){
		printf("This matrix is symmetric. \n");
	}
	
	else{
		printf("Is not symmetric. \n");
	}

}


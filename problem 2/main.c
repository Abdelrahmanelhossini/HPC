#include <stdio.h>
#include <stdlib.h>
//20210609
//20200088

// انا كاتب كود mpi بس في ايرور بسيط بس مش لاقي ليه حل ف عملت الكود في كومنت
//#include <mpi.h>
//int main(int argc, char** argv) {
/*    int r,c,r2,c2;
    FILE *fptr;
    fptr = fopen("textfile.txt", "r");
    char myString[100];
    if(fptr != NULL) {
    while(fgets(myString, 100, fptr)) {
        scanf("%d", &r);
    }
    }
    else
        printf("Not able to open the file.");
    fclose(fptr);*/
int main(){
    int r,c,r2,c2 ,rank, size=4;
    int** arr = (int**)malloc(r * sizeof(int*));
    int** arr2 = (int**)malloc(r * sizeof(int*));
    int f;
    printf("enter num 1 for input file  or 0 for user input \n");
    scanf("%d",&f);
    if (f ==1){
    FILE *fptr;
    fptr = fopen("textfile1.txt", "r");
    char myString[200];
        fscanf(fptr,"%d",&r);
        fscanf(fptr,"%d",&c);
        fscanf(fptr,"%d",&r2);
        fscanf(fptr,"%d",&c2);

        for ( int i = 0; i < r; i++)
            arr[i] = (int*)malloc(c * sizeof(int));
        printf("matrix 1 \n");
        for ( int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                fscanf(fptr,"%d",&arr[i][j]);
        for ( int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                printf("%d ", arr[i][j]);}
            printf("\n");
        }


        for ( int i = 0; i < r2; i++)
            arr2[i] = (int*)malloc(c2 * sizeof(int));
        printf ("matrix 2\n");

        //fscanf(fptr,"%d",&r2);
        //fscanf(fptr,"%d",&c2);
        for ( int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                fscanf(fptr,"%d",&arr2[i][j]);
        for ( int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++)

                printf("%d ", arr2[i][j]);
            printf("\n");
        }
        printf("result matrix \n");
//int r,c,r2,c2 ,rank, size=4;
   //int sub_size = r / size;
   // int* sub_arr, *sub_arr2, *sub_result;

    //printf("%d",r);
        //printf("%d",c);
    fclose(fptr);}
    else if (f==0){
    //MPI_Status status;


    printf("no of rows for matix 1 :  ");
    scanf("%d",&r);
    printf("no of cols for matix 1 :  ");
    scanf("%d",&c);
    //  printf("rows: %d" ,r);
    //printf("cols :%d",c);
    //int** arr = (int**)malloc(r * sizeof(int*));
    for ( int i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));
    int count =0;
    printf ("matrix 1\n");
    for ( int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d",&arr[i][j]);
    for ( int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("no of rows for matix 2 : ");
    scanf("%d",&r2);
    printf("no of cols for matix 2 :  ");
    scanf("%d",&c2);

    // int** arr2 = (int**)malloc(r * sizeof(int*));
    for ( int i = 0; i < r; i++)
        arr2[i] = (int*)malloc(c * sizeof(int));

    printf ("matrix 2\n");
    for ( int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d",&arr2[i][j]);
    for ( int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", arr2[i][j]);
        printf("\n");
    }}
    int result[r][c2];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            result[i][j]=0;
            for(int k=0;k<c;k++)
            {
                result[i][j]+=arr[i][k]*arr2[k][j];
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d \t",result[i][j]);
        }
        printf("\n");
    }

    //MPI_Init(&argc, &argv);
    //MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    //MPI_Comm_size(MPI_COMM_WORLD, &size);
/*if (rank==0){
printf("no of rows for matix 1 :  ");
    scanf("%d",&r);
    printf("no of cols for matix 1 :  ");
    scanf("%d",&c);
  //  printf("rows: %d" ,r);
    //printf("cols :%d",c);
    //int** arr = (int**)malloc(r * sizeof(int*));
    for ( int i = 0; i < r; i++)
        arr[i] = (int*)malloc(c * sizeof(int));
    int count =0;
    printf ("matrix 1\n");
    for ( int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d",&arr[i][j]);
    for ( int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("no of rows for matix 2 : ");
    scanf("%d",&r2);
    printf("no of cols for matix 2 :  ");
    scanf("%d",&c2);

   // int** arr2 = (int**)malloc(r * sizeof(int*));
    for ( int i = 0; i < r; i++)
        arr2[i] = (int*)malloc(c * sizeof(int));

    printf ("matrix 2\n");
    for ( int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d",&arr2[i][j]);
    for ( int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", arr2[i][j]);
        printf("\n");
    }

        for ( int i = 1; i < size; i++) {
        sub_arr=&(arr[i*sub_size][0]);
         sub_arr2=&(arr2[0][0]);


        MPI_Send(&sub_arr, sub_size *c , MPI_INT, i, 0, MPI_COMM_WORLD);

        MPI_Send (&sub_arr2, r2 * c2, MPI_INT, i, 1, MPI_COMM_WORLD);
    }
    int result[r][c2];
    sub_arr= &(arr[0][0]);
    sub_arr2=&(arr2[0][0]);
    sub_result=& (result[0][0]);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c2;j++)
        {
            *(sub_result+i*r+j)=0;
            for(int k=0;k<c2;k++)
            {
                (sub_result[i*r][j])+=*(sub_A+i*r+k)* *(sub_B+k*r2+j);
            }
        }
    }

    for ( int i = 1; i < size; i++) {
        sub_C = &(result[i * sub_size][0]);
        MPI_Recv(&sub_C, sub_size * c2, MPI_INT, i, 2, MPI_COMM_WORLD,
                 &status);
    }
    printf("Matrix C:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    }
else

{
    sub_size = r / size;
    sub_A = malloc(sub_size * c * sizeof(int));

    MPI_Recv(&sub_A, sub_size *c ,MPI_INT , 0 , 0 ,MPI_COMM_WORLD,&status);

    sub_B=malloc(r2 * c2 * sizeof(int));

    MPI_Recv(&sub_B, r2*c2 ,MPI_INT , 0 ,1,MPI_COMM_WORLD,&status);

    sub_C=malloc(sub_size*c2*sizeof(int));

    for(int i=0;i<sub_size;i++){
        for(int j=0;j<c2;j++){
            *(sub_C+i*r+j)=0;
            for(int k=0;k<r;k++){
                *(sub_C+i*r+j)+=*(sub_A+i*r+k)*(*(sub_B+k*r2+j));
            }
        }
    }
    MPI_Send(&sub_C ,sub_size*c2,MPI_INT , 0 ,2,MPI_COMM_WORLD);

}
 //   MPI_Send(sub_C ,sub_size*c2,MPI_INT , 0 ,2,MPI_COMM_WORLD);

    //MPI_Recv(sub_C, sub_size * c2, MPI_INT, i, 2, MPI_COMM_WORLD,
      //       &status);

/*int result[r][c2];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            result[i][j]=0;
            for(int k=0;k<c;k++)
            {
                result[i][j]+=arr[i][k]*arr2[k][j];
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d \t",result[i][j]);
        }
        printf("\n");
    }
*/
 //   MPI_Finalize();
    return 0;
}

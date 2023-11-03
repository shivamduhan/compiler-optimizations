#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int  main(){
int **matrix = (int **)malloc(50000 * sizeof(int*));
for(int i = 0; i < 50000; i++) {
    matrix[i] = (int *)malloc(10000 * sizeof(int));
}
int *arr1 = (int *)malloc(10000 * sizeof(int*));
int *arr2 = (int *)malloc(10000 * sizeof(int*));
int *arr3 = (int *)malloc(10000 * sizeof(int*));
int *arr4 = (int *)malloc(10000 * sizeof(int*));

for(int i = 0; i < 10000; i++) {
arr1[i] = 1;
arr2[i] = 1;
arr3[i] = 1;
arr4[i] = 1;

}
for(int i = 0; i < 50000; i++) {
for(int j = 0; j < 10000; j++) {
matrix[i][j] = 1; }}

int sum = 0;

int poor_s = clock();
for (int j = 0; j < 10000; j++) {
for (int i = 0; i < 50000; i++) {
sum += matrix[i][j]; }}

int poor_e = clock();
printf("done poorly\n");
int good_s = clock();

for (int i = 0; i < 50000; i++) {
for (int j = 0; j < 10000; j++) {
sum += matrix[i][j];}}
int good_e = clock();

for(int i = 0; i < 50000; i++) {
    free(matrix[i]);
}
//loop 
int fission_s = clock();
for (int i = 0; i < 10000; i++) {
arr3[i] = min(arr1[i],arr2[i]);}

for(int i = 0; i < 10000; i++) {
arr4[i] = max(arr1[i], arr2[i]);}
int fission_e = clock();

int fusion_s = clock();
for(int i = 0; i < 10000; i++) {
arr3[i] = min(arr1[i], arr2[i]);
arr4[i] = max(arr1[i], arr2[i]);}
int fusion_e = clock();

free(matrix);
free(arr1);
free(arr2);
free(arr3);
free(arr4);

double speedup = 1/(((double)(good_e - good_s)) / ((double)(poor_e - poor_s)));
printf("Loop interchange achieved a speedup of %f\n", speedup);

double fusion = 1/(((double)(fusion_e - fusion_s)) / ((double)(fission_e - fission_s)));
printf("Loop fusion achieved a speedup of %f\n", fusion);

return 0;}

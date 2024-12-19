#include <stdio.h>
#include <stdlib.h>
int count_elements(FILE *input)
{
    int cnt = 0;
    int element = 0;
    int result = 0;
    while ((result = fscanf(input, "%d", &element)) == 1) {
        cnt += 1;
    }
    if (result != EOF) {
        return -1;
    }
    rewind(input);
    return cnt;
}
int read_array(FILE *input, int *length, int **array)
{
    *length = count_elements(input);
    if (*length == -1 || *length == 0) {
        return -1;
    }
    *array = (int*)malloc((*length) * sizeof(int));
    if (*array == NULL) {
        return -1;
    }
    for (int i = 0; i < *length; i++) {
        fscanf(input, "%d", &((*array)[i]));
    }
    return 1;
}
int main(int argc, char *argv[])
{
    int n = 200;
    int flag = 0;
    int *array = NULL;
    int size_a = 0;
    FILE *input = NULL;
    if (argc != 2) {
        printf("error\n");
        return -1;
    }
    input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("error\n");
        return -1;
    }
    if (read_array(input, &size_a, &array) == -1) {
        printf("error\n");
        return -1;
    }
    for (int i = 0; i < size_a; ++i) {
        for (int j = 0; j < size_a; ++j) {
            if (array[i] + array[j] == 2020 && (flag == 0)) {
                flag = 1;
                printf("%d\n", array[i] * array[j]);
            }
        }
    }
    free(array);
    return 0;
}
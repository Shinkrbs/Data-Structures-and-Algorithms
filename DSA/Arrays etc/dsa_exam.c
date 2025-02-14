#include <stdio.h>
#include <stdlib.h>

void jagged_array_1();
void func1();
void func2();
void func3();

int main()
{
    //jagged_array_1();
    //func1();
    //func2();
    func3();
    return 0;
}

void jagged_array_1()
{
    void** arr = (void**)malloc(sizeof(void*) * 5);
    *(arr) = NULL;
    *(arr + 1) = (int*)malloc(sizeof(int) * 4);
    *(arr + 2) = (char*)malloc(sizeof(char) * 3);
    *(arr + 3) = NULL;
    *(arr + 4) = (double*)malloc(sizeof(double) * 3);

    //Typecasting
    //*((int*)(*(arr + 1))) = 4;
    ((int*)arr[1])[0] = 4;
    *((int*)(*(arr + 1)) + 1) = 7;
    *((int*)(*(arr + 1)) + 2) = 9;
    *((int*)(*(arr + 1)) + 3) = 13;

    ((char*)arr[2])[0] = 'a';
    //*((char*)(*(arr + 2))) = 'a';
    *((char*)(*(arr + 2)) + 1) = 'b';
    *((char*)(*(arr + 2)) + 2) = 'c';

    *((double*)(*(arr + 4))) = 12.1;
    *((double*)(*(arr + 4)) + 1) = 7.5;
    *((double*)(*(arr + 4)) + 2) = 9.88;

    //printf("%c", *((char*)(*(arr + 1)) + 2));
    printf("%c", ((char*)arr[2])[0]);
    //printf("%.2lf", ((double*)arr[4])[2]);
    // printf("%d\n", ((int*)arr[1])[0]);
    // ((int*)arr[1])[0] = 100;
    // printf("%d\n", ((int*)arr[1])[0]);

    for(int i = 0; i < 5; i++)
        free(*(arr + i));
    free(arr);
}

void func1()
{
    int n;
    scanf("%d", &n);
    //int arr[5] = {0, 0, 0, 0, 0};
    int* arr = (int*)malloc(sizeof(int) * (n + 1));
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        //arr[x % 5]++; //Increment the value inside the array
        arr[x]++;
    }

    for(int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    //printf("%d", arr[2]);
    free(arr);
}

void func2()
{
    // Shifting
    int x[5] = {6, 1, 4, 3, 2};
    int a = 0, b = 5 - 1, c;

    while(a < b)
    {
        c = x[a];
        x[a] = x[b];
        x[b] = c;
        a++;
        b--;
    }

    for(int i = 0; i < 5; i++)
        printf("%d ", x[i]);
}

void func3()
{
    int a = 21;
    char b = 'x';
    double c = 1.21;
    int i = 2;

    void* m;
    void* o;
    int* n;
    int* p = &a;
    n = p;
    o = n;
    m = o;
    printf("%d\n", *((int*)m));

    char* q = &b;
    o = q;
    m = o;
    printf("%c\n", *((char*)m));

    double* d = &c;
    double** e = &d;
    double*** f = &e;
    printf("%.2lf\n", ***f);

    void* k = &i;
    void** l = &k;
    void*** v = &l;
    printf("%d\n", ***((int***)v));
}   
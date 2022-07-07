
// Function declaration
double **createMat(int m, int n);
void readMat(double **p, int m, int n);
void print(double **p, int m, int n);
double **loadtxt(char *str, int m, int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_inv(double **mat, int m);
double **matmul(double **a, double **b, int m, int n, int p);
double **transpose(double **a, int m, int n);
void uniform(char *str, int len);
void gaussian(char *str, int len);
void triangular(char *str,char* uniform1,char*uniform2, int len);
void bernoulie(char *str, int len);
void chi_square(char *str, char *str1, char *str2, int len);
void Rayleigh(char *str, char *str1, char *str2, int len);
double mean(char *str);
double variance(char *str);
// End function declaration

// Defining the function for matrix creation
double **createMat(int m, int n)
{
    int i;
    double **a;

    // Allocate memory to the pointer
    a = (double **)malloc(m * sizeof(*a));
    for (i = 0; i < m; i++)
        a[i] = (double *)malloc(n * sizeof(*a[i]));

    return a;
}
// End function for matrix creation

// Defining the function for reading matrix
void readMat(double **p, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &p[i][j]);
        }
    }
}
// End function for reading matrix

// Read  matrix from file
double **loadtxt(char *str, int m, int n)
{
    FILE *fp;
    double **a;
    int i, j;

    a = createMat(m, n);
    fp = fopen(str, "r");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fp, "%lf", &a[i][j]);
        }
    }
    // End function for reading matrix from file

    fclose(fp);
    return a;
}

// Defining the function for printing
void print(double **p, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%lf ", p[i][j]);
        printf("\n");
    }
}
// End function for printing

// Defining the function for norm

double linalg_norm(double **a, int m)
{
    int i;
    double norm = 0.0;

    for (i = 0; i < m; i++)
    {
        norm = norm + a[i][0] * a[i][0];
    }
    return sqrt(norm);
}
// End function for norm

// Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
    int i, j;
    double **c;
    c = createMat(m, n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}
// End function for difference of matrices

// Defining the function for inverse of 2x2 matrix

double **linalg_inv(double **mat, int m)
{
    double **c, det;
    c = createMat(m, m);

    det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    c[0][0] = mat[1][1] / det;
    c[0][1] = -mat[1][0] / det;
    c[1][0] = -mat[0][1] / det;
    c[1][1] = mat[0][0] / det;

    return c;
}
// End  function for inverse of 2x2 matrix

// Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
    int i, j, k;
    double **c, temp = 0;
    c = createMat(m, p);

    for (i = 0; i < m; i++)
    {
        for (k = 0; k < p; k++)
        {
            for (j = 0; j < n; j++)
            {
                temp = temp + a[i][j] * b[j][k];
            }
            c[i][k] = temp;
            temp = 0;
        }
    }
    return c;
}
// End function for difference of matrices

// Defining the function for transpose of matrix

double **transpose(double **a, int m, int n)
{
    int i, j;
    double **c;
    // printf("I am here");
    c = createMat(n, m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            c[i][j] = a[j][i];
            //  printf("%lf ",c[i][j]);
        }
    }
    return c;
}
// End function for transpose of matrix

// Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
    int i;
    FILE *fp;

    fp = fopen(str, "w");
    // Generate numbers
    for (i = 0; i < len; i++)
    {
        fprintf(fp, "%lf\n", (double)rand() / RAND_MAX);
    }
    fclose(fp);
}
// End function for generating uniform random numbers

// Defining the function for calculating the mean of random numbers
double mean(char *str)
{
    int i = 0, c;
    FILE *fp;
    double x, temp = 0.0;

    fp = fopen(str, "r");
    // get numbers from file
    while (fscanf(fp, "%lf", &x) != EOF)
    {
        // Count numbers in file
        i = i + 1;
        // Add all numbers in file
        temp = temp + x;
    }
    fclose(fp);
    temp = temp / (i - 1);
    return temp;
}
// End function for calculating the mean of random numbers

double variance(char *str)
{
    int count = 0;
    FILE *fp;
    double x, sum = 0.0;
    fp = fopen(str, "r");
    double square = 0;
    double mean;
    double variance;
    // get numbers from file
    while (fscanf(fp, "%lf", &x) != EOF)
    {
        // Count numbers in file
        count = count + 1;
        // Add all numbers in file
        sum = sum + x;

        // Adding the squares of numbers
        square = square + x * x;
    }
    fclose(fp);
    variance = square / count - mean * mean;
    return variance;
}

// Defining the function for generating Gaussian random numbers
void gaussian(char *str, int len)
{
    int i, j;
    double temp;
    FILE *fp;

    fp = fopen(str, "w");
    // Generate numbers
    for (i = 0; i < len; i++)
    {
        temp = 0;
        for (j = 0; j < 12; j++)
        {
            temp += (double)rand() / RAND_MAX;
        }
        temp -= 6;
        fprintf(fp, "%lf\n", temp);
    }
    fclose(fp);
}
void triangular(char *str,char* uniform1,char*uniform2, int len)
{
    FILE*fp = fopen(str,"w");
    FILE*fp1 = fopen(uniform1,"r");
    FILE*fp2 = fopen(uniform2,"r");
    int i;
    double u1 = 0.0;
    double u2 = 0.0;
    double t;
    for(i=0;i<len;i++){
      fscanf(fp1,"%lf",&u1);
      fscanf(fp2,"%lf",&u2);
      t = u1 + u2;
      fprintf(fp,"%lf\n",t);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
void bernoulie(char *str, int len)
{
    int i;
    FILE *fp;
    fp = fopen(str, "w");
    double u = 0.0;
    for (i = 0; i < len; i++)
    {
        u = (double)rand() / RAND_MAX;
        if (u - 0.5 > 1e-5)
        {
            fprintf(fp, "%lf\n", 1.0);
        }
        else
        {
            fprintf(fp, "%lf\n", -1.0);
        }
    }
    fclose(fp);
}

//Defining function for Generating chi square random numbers for k = 2.
void chi_square(char *str, char *str1, char *str2, int len)
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp;
    double x1, x2, v;
    fp1 = fopen(str1, "r");
    fp2 = fopen(str2, "r");
    fp = fopen(str, "w");
    int i;
    for (i = 0; i < len; i++)
    {
        fscanf(fp1, "%lf", &x1);
        fscanf(fp2, "%lf", &x2);
        v = x1 * x1 + x2 * x2;
        fprintf(fp, "%lf\n", v);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
//End of the function

// Defining the function to generate the rayliegh distribution random numbers.
void Rayleigh(char *str, char *str1, char *str2, int len)
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp;
    double x1, x2, v;
    fp1 = fopen(str1, "r");
    fp2 = fopen(str2, "r");
    fp = fopen(str, "w");
    int i;
    for (i = 0; i < len; i++)
    {
        fscanf(fp1, "%lf", &x1);
        fscanf(fp2, "%lf", &x2);
        v = x1 * x1 + x2 * x2;
        fprintf(fp, "%lf\n", sqrt(v));
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
// End of function



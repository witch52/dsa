#include <stdio.h>

struct poly {
    int coeff;
    int pow;
};

void enterpoly(struct poly polyn[], int *n);
void add(struct poly poly1[], int n1, struct poly poly2[], int n2, struct poly poly3[], int *n3);
void multiply(struct poly poly1[], int n1, struct poly poly2[], int n2, struct poly poly3[], int *n3);
void combine_terms(struct poly poly[], int n, struct poly result[], int *n_result);
void printPoly(struct poly polyn[], int n);

int main() {
    struct poly first[10], second[10], result_add[20], temp_result_mul[100], final_result_mul[100];
    int n1, n2, n3_add = 0, n_temp_mul = 0, n_final_mul = 0;
    int c, y = 1;

    while (y == 1) {
        printf("Choose an operation:\n");
        printf("1. Add Polynomials\n");
        printf("2. Multiply Polynomials\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter first polynomial\n");
                enterpoly(first, &n1);
                printf("Enter second polynomial\n");
                enterpoly(second, &n2);
                add(first, n1, second, n2, result_add, &n3_add);
                printf("The resulting polynomial after addition is:\n");
                printPoly(result_add, n3_add);
                break;
            case 2:
                printf("Enter first polynomial\n");
                enterpoly(first, &n1);
                printf("Enter second polynomial\n");
                enterpoly(second, &n2);
                multiply(first, n1, second, n2, temp_result_mul, &n_temp_mul);
                combine_terms(temp_result_mul, n_temp_mul, final_result_mul, &n_final_mul);
                printf("The resulting polynomial after multiplication is:\n");
                printPoly(final_result_mul, n_final_mul);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Want to continue? Enter 1 for Yes, any other number for No: ");
        scanf("%d", &y);
    }

    return 0;
}

void enterpoly(struct poly polyn[], int *n) {
    printf("Enter number of terms in polynomial: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &polyn[i].coeff, &polyn[i].pow);
    }
}

void add(struct poly poly1[], int n1, struct poly poly2[], int n2, struct poly poly3[], int *n3) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].pow > poly2[j].pow) {
            poly3[k++] = poly1[i++];
        } else if (poly1[i].pow < poly2[j].pow) {
            poly3[k++] = poly2[j++];
        } else {
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff;
            poly3[k++].pow = poly1[i].pow;
            i++;
            j++;
        }
    }
    while (i < n1) {
        poly3[k++] = poly1[i++];
    }
    while (j < n2) {
        poly3[k++] = poly2[j++];
    }
    *n3 = k;
}

void multiply(struct poly poly1[], int n1, struct poly poly2[], int n2, struct poly poly3[], int *n3) {
    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            poly3[k].coeff = poly1[i].coeff * poly2[j].coeff;
            poly3[k].pow = poly1[i].pow + poly2[j].pow;
            k++;
        }
    }
    *n3 = k;
}

void combine_terms(struct poly poly[], int n, struct poly result[], int *n_result) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int coeff = poly[i].coeff;
        int pow = poly[i].pow;
        for (int j = i + 1; j < n; j++) {
            if (poly[j].pow == pow) {
                coeff += poly[j].coeff;
                poly[j].pow = -1;
            }
        }
        if (poly[i].pow != -1) {
            result[k].coeff = coeff;
            result[k].pow = pow;
            k++;
        }
    }
    *n_result = k;
}

void printPoly(struct poly polyn[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", polyn[i].coeff, polyn[i].pow);
        if (i != n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}
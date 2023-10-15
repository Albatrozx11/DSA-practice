#include <stdio.h>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
};

// Function to add two polynomials
void addPolynomials(struct Term poly1[], int size1, struct Term poly2[], int size2, struct Term result[], int *size_result) {
    int i = 0, j = 0, k = 0;

    // Continue adding terms until one of the polynomials is exhausted
    while (i < size1 && j < size2) {
        if (poly1[i].exponent > poly2[j].exponent) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result[k++] = poly2[j++];
        } else {
            // Add coefficients when exponents are equal
            result[k].exponent = poly1[i].exponent;
            result[k++].coefficient = poly1[i++].coefficient + poly2[j++].coefficient;
        }
    }

    // Copy the remaining terms from the first polynomial
    while (i < size1) {
        result[k++] = poly1[i++];
    }

    // Copy the remaining terms from the second polynomial
    while (j < size2) {
        result[k++] = poly2[j++];
    }

    // Set the size of the result polynomial
    *size_result = k;
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        if (i < size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &size1);

    struct Term poly1[size1];

    // Input coefficients and exponents for Polynomial 1
    for (int i = 0; i < size1; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &poly1[i].coefficient);

        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &poly1[i].exponent);
    }

    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &size2);

    struct Term poly2[size2];

    // Input coefficients and exponents for Polynomial 2
    for (int i = 0; i < size2; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &poly2[i].coefficient);

        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &poly2[i].exponent);
    }

    // Assuming the result polynomial can have at most size1 + size2 terms
    struct Term result[size1 + size2];
    int size_result;

    // Perform polynomial addition
    addPolynomials(poly1, size1, poly2, size2, result, &size_result);

    // Display the input polynomials
    printf("\nPolynomial 1: ");
    displayPolynomial(poly1, size1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2, size2);

    // Display the result polynomial
    printf("\nResult: ");
    displayPolynomial(result, size_result);

    return 0;
}

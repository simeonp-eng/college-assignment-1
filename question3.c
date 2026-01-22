#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

int main() {
    struct Complex c1, c2, sum, product;
    printf("Enter first complex number:\n");
    printf("Real part: ");
    scanf("%f", &c1.real);
    printf("Imaginary part: ");
    scanf("%f", &c1.imag);
    printf("\nEnter second complex number:\n");
    printf("Real part: ");
    scanf("%f", &c2.real);
    printf("Imaginary part: ");
    scanf("%f", &c2.imag);
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    product.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    product.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    printf("\n--- Results ---\n");
    printf("Sum = %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Product = %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}
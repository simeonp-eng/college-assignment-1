#include <stdio.h>

struct Car {
    int carID;
    char model[50];
    float rentalRate;
};

int main() {
    struct Car cars[3];
    int days, i;
    float totalCost;
    for(i = 0; i < 3; i++) {
        printf("\nEnter details of Car %d\n", i + 1);
        printf("Car ID: ");
        scanf("%d", &cars[i].carID);

        printf("Model: ");
        scanf(" %[^\n]", cars[i].model);

        printf("Rental Rate per Day: ");
        scanf("%f", &cars[i].rentalRate);
    }
    printf("\nEnter number of rental days: ");
    scanf("%d", &days);
    printf("\n--- Car Rental Details ---\n");
    for(i = 0; i < 3; i++) {
        totalCost = cars[i].rentalRate * days;
        printf("\nCar ID: %d", cars[i].carID);
        printf("\nModel: %s", cars[i].model);
        printf("\nRental Rate per Day: %.2f", cars[i].rentalRate);
        printf("\nTotal Cost for %d days: %.2f\n", days, totalCost);
    }

    return 0;
}

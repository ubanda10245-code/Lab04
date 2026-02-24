#include <stdio.h>

float celsius_to_fahrenheit (float celsius){}

float fahrenheit_to_celsius (float fahrenheit){}

float celsius_to_kelvin (float celsius){}

float kelvin_to_celsius (float kelvin){}

float fahrenheit_to_kelvin (float fahrenheit){}

float kelvin_to_fahrenheit (float kelvin){}

void categorize_temperature(float celsius){}

int main() {
    float temp;
    int category;
    int conversion;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &category);

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &conversion);


}
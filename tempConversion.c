#include <stdio.h>

// Temperature Conversion functions
// Converts Celsius to Fahrenheit using F = (9/5)C + 32
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

// Converts Fahrenheit to Celsius using C = (5/9)(F - 32)
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

// Converts Celsius to Kelvin using K = C + 273.15
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Converts Kelvin to Celsius using C = K - 273.15
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Converts Fahrenheit to Kelvin
// Converts Fahrenheit to Celsius first, then Celsius to Kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    return celsius_to_kelvin(celsius);
}

// Converts Kelvin to Fahrenheit
// Converts Kelvin to Celsius first, then Celsius to Fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    return celsius_to_fahrenheit(celsius);
}

int main() {
    float temp, celsiusTemp, result;
    int currentScale, targetScale;

    while(1) {
        // Prompt the user for temperature value, current scale, and target scale.
        printf("Enter the temperature: ");
        scanf("%f", &temp);
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &currentScale);
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &targetScale);

        // Invalid temperature values for Kelvin
        if (currentScale == 3 && temp < 0) {
            printf("Error: Invalid temperature. Kelvin cannot be negative. Please try again.\n");
            // Skip the rest of the loop and prompt the user again
            continue;
        }

        // Perform the temperature conversions and store the result in the float variable
        //  'result', and 'celsiusTemp' will hold the Celsius value for the categorization.
        // Celsius
        if (currentScale == 1 && targetScale == 2) { // to Fahrenheit
            result = celsius_to_fahrenheit(temp);
            celsiusTemp = temp; // Use original Celsius temperature

        } else if (currentScale == 1 && targetScale == 3) { // to Kelvin
            result = celsius_to_kelvin(temp);
            celsiusTemp = temp; // Use original Celsius temperature

        // Fahrenheit
        } else if (currentScale == 2 && targetScale == 1) { // to Celsius
            result = fahrenheit_to_celsius(temp);
            celsiusTemp = result; // Use the converted Celsius temperature

        } else if (currentScale == 2 && targetScale == 3) { // to Kelvin
            result = fahrenheit_to_kelvin(temp);
            celsiusTemp = fahrenheit_to_celsius(temp); // Convert original Fahrenheit to Celsius

        // Kelvin
        } else if (currentScale == 3 && targetScale == 1) { // to Celsius
            result = kelvin_to_celsius(temp);
            celsiusTemp = result; // Use the converted Celsius temperature

        } else if (currentScale == 3 && targetScale == 2) { // to Fahrenheit
            result = kelvin_to_fahrenheit(temp);
            celsiusTemp = kelvin_to_celsius(temp); // Convert original Kelvin to Celsius

        // Invalid conversion choice (same scale or invalid scale values)
        } else {
            printf("Error: Invalid conversion choice. Please try again.\n");
            // Skip the rest of the loop and prompt the user again
            continue;
        }

        // Output the correctly formatted converted temperature
        if (targetScale == 1) {
            printf("\nConverted temperature: %.2f°C\n", result);
        } else if (targetScale == 2) {
            printf("\nConverted temperature: %.2f°F\n", result);
        } else if (targetScale == 3) {
            printf("\nConverted temperature: %.2fK\n", result);
        }

        // Categorize the temperature based on the Celsius value
        printf("Temperature category: ");
        if (celsiusTemp < 0) {
            printf("Freezing\nWeather advisory: It's freezing! Stay indoors.\n");
        } else if (celsiusTemp >= 0 && celsiusTemp < 10) {
            printf("Cold\nWeather advisory: Wear a jacket.\n");
        } else if (celsiusTemp >= 10 && celsiusTemp < 25) {
            printf("Comfortable\nWeather advisory: You should feel comfortable.\n");
        } else if (celsiusTemp >= 25 && celsiusTemp < 35) {
            printf("Hot\nWeather advisory: Stay hydrated.\n");
        } else { // celsius >= 35
            printf("Extreme Heat\nWeather advisory: Extreme heat! Stay indoors and cool.\n");
        }

        break; // Exit the loop
    }

    return 0;
}
#include <stdio.h>
#include <math.h>


typedef struct {
    double weight;
    double altitude;
    double temperature;
    double wind_speed;
    double wind_direction;

} performance;

typedef struct {
    double takeoff_distance;
    double climb_rate;
    double fuel_consumption;
} output;


double takeOfDistance(double weight, double altitude, double temperature) {

    double takeoff_distance = weight * (1.0 + altitude / 1000.0) * (1.0 + temperature / 40.0);
    return takeoff_distance;
}


double climbRate(double weight, double altitude, double temperature, double wind_speed, double wind_direction) {

    double climb_rate = (weight / 1000.0) * (1.0 + altitude / 1000.0) * (1.0 - wind_speed / 20.0) * (1.0 + temperature / 60.0);
    return climb_rate;
}


double fuelConsumtion(double weight, double altitude, double temperature) {
    double fuel_consumption = weight * (1.0 + altitude / 2000.0) * (1.0 + temperature / 80.0);
    return fuel_consumption;
}



int main() {
    performance parameters;
    output metrics;

    int input;
    float distanec;

    printf("Enter 1 for units in meter \n");
    printf("Enter 2 for unit in feet \n");
    scanf("%d",&input);

    printf("Enter weight of the aircraft: ");
    scanf("%lf", &parameters.weight);

    printf("Enter altitude of the aircraft: ");
    scanf("%lf", &parameters.altitude);


    printf("Enter temperature of the aircraft: ");
    scanf("%lf", &parameters.temperature);


    printf("Enter wind speed of the aircraft: ");
    scanf("%lf", &parameters.wind_speed);


    printf("Enter wind direction of the aircraft: ");
    scanf("%lf", &parameters.wind_direction);




    metrics.takeoff_distance = takeOfDistance(parameters.weight, parameters.altitude, parameters.temperature);
    metrics.climb_rate = climbRate(parameters.weight, parameters.altitude, parameters.temperature, parameters.wind_speed, parameters.wind_direction);
    metrics.fuel_consumption = fuelConsumtion(parameters.weight, parameters.altitude, parameters.temperature);


        switch(input){
        case 1:
           distanec = metrics.takeoff_distance;
           printf("Takeoff distance: %.2f meters\n", distanec);
           break;
        case 2:
            distanec = metrics.takeoff_distance * 3.2808;
              printf("Takeoff distance: %.2f feet\n", distanec);
                break;
        default: printf("None");

    }





    printf("Climb rate: %.2f meters per second\n", metrics.climb_rate);
    printf("Fuel consumption: %.2f liters per hour\n", metrics.fuel_consumption);

    return 0;
}


#include <stdlib.h>
#include <time.h>

// Define the DHT22Simulation class
typedef struct {
    float temperature;
    float humidity;
} DHT22Simulation;

// Function to generate random temperature and humidity values
void generate_values(DHT22Simulation* dht22_simulation) {
    srand(time(0)); // Use current time as seed for random generator

    // Generate random temperature between -40.0 and 80.0 degrees Celsius
    dht22_simulation->temperature = ((float)rand()/(float)(RAND_MAX)) * 120.0 - 40.0;

    // Generate random humidity between 0.0 and 100.0%
    dht22_simulation->humidity = ((float)rand()/(float)(RAND_MAX)) * 100.0;
}

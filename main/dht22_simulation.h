#ifndef DHT22_SIMULATION_H
#define DHT22_SIMULATION_H

typedef struct {
    float temperature;
    float humidity;
} DHT22Simulation;

void generate_values(DHT22Simulation* dht22_simulation);

#endif // DHT22_SIMULATION_H

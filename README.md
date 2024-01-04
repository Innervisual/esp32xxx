Jag har använt mig av en esp32 utvecklingskort och ESP-IDF utvecklingsprogramvara för att laga en sensor DHT22 simulering som läser temperatur och fuktighetsvärden värden.
Därefter har jag lagat unit tester och konfigurat programvaran till att skicka all utdata till min ledskärm via den seriella monitor funktionen som finns på ESP-IDF programvaran.
På utdata fick jag den att visa följande, se nedan bild.
![image](https://github.com/Innervisual/esp32xxx/assets/98667242/bf3ee5d4-6bb4-4b25-9cdf-b6ad1ca3288a)
Dessutom har jag lagt till en funktionalitet för att uppdatera den inbyggda programvaran via OTA (Over the Air updates), så att jag kan vidarutveckla och updatera programvaran genom wifi.
Mvh
JP

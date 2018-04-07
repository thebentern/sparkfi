# sparkfi

[![Build Status](https://travis-ci.org/thebentern/sparkfi.svg?branch=master)](https://travis-ci.org/thebentern/sparkfi)

8 channel relay based firework igniter for Wemos D1 mini ESP8266 platform

## Basic installation and usage

* Clone repository

* Install [Platform IO](http://platformio.org/)

* Modify the definitions in main.ino to match your target environment

Wifi connection settings:

```cpp
#define WIFI_SSID "MyWifiAp"
#define WIFI_PASSWORD "MyPassword"
```

* Change default pin mappings (optional). In `main.ino` the channels are mapped to pins in the following array by index. This can be changed to suit whichever pins that support 5v digital write on the board.

```cpp
const int PIN_MAPPINGS[] = { 0, D1, D2, D3, D4, D5, D6, D7, D8 };
```

* Run Platform IO build scripts:

```cmd
platformio run --target upload
platformio device monitor --baud 9600
```

### Troubleshooting

#### Serial logging

Some basic diagnostic logging is written to the serial log. Start there if you are having network issues.

![Serial logging](serial.png)

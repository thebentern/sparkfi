# sparkfi

[![Build Status](https://travis-ci.org/thebentern/sparkfi.svg?branch=master)](https://travis-ci.org/thebentern/sparkfi)

8 channel relay based firework igniter for Wemos D1 mini ESP8266 platform

![Web interface](interface.png)

## Basic installation

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

## Basic example of wiring

![Fritzing diagram](example_sketch_bb.png)

### Troubleshooting

#### Serial logging

Some basic diagnostic logging is written to the serial log. Start there if you are having network issues.

![Serial logging](serial.PNG)

## Changing the web interface

As a convenience when I started developing the html for this project. I created it in the `src/index.html` fle. Because copying and serving a hefty file from SPIFFS file system on the ESP8266 is a somewhat unnecessary complication, I chose to generate a method in `html.ino` to serve up the html. In order to get any changes in the html into the `html.ino`, I wrote a very crude NodeJs solution to generate the `html.ino` from `index.html`. All of that being said, if you wish to make any changes to the interface, simply change the `index.html` file and execute 
```cmd
node index.js
``` 
in the root directory of the repository. That will regenerate the html in `html.ino`.

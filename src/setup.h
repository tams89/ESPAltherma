#pragma once
// Setup your credentials and mqtt info here.
// To keep secrets out of the repo, create a local file `src/setup_local.h` and
// add it to `.gitignore`. If `setup_local.h` exists it will be included and
// will override the defaults below.

// Try to include local setup if it exists. This avoids forcing developers to
// modify project files or commit secrets.
#if defined(__has_include)
#  if __has_include("setup_local.h")
#    include "setup_local.h"
#  endif
#endif

// Fallback defaults (safe placeholders) - these will be used if no
// `setup_local.h` overrides are provided. We use #ifndef to let local files
// or -D defines override them.
#ifndef WIFI_SSID
#define WIFI_SSID "<YOUR_SSID>" // set your SSID in src/setup_local.h
#endif

#ifndef WIFI_PWD
#define WIFI_PWD "<YOUR_WIFI_PASSWORD>" // set in src/setup_local.h
#endif

#ifndef MQTT_SERVER
#define MQTT_SERVER "<MQTT_SERVER>" // set in src/setup_local.h
#endif

#ifndef MQTT_USERNAME
#define MQTT_USERNAME "<MQTT_USERNAME>"
#endif

#ifndef MQTT_PASSWORD
#define MQTT_PASSWORD "<MQTT_PASSWORD>"
#endif
#ifndef MQTT_PORT
#define MQTT_PORT 1883
#endif
//#define MQTT_ENCRYPTED // uncomment if MQTT connection is encrypted via TLS

#define FREQUENCY 30000 //query values every 30 sec

#if defined(ARDUINO_M5Stick_C) || defined(ARDUINO_M5Stick_C_Plus) || defined(ARDUINO_M5Stick_C_Plus2)  || defined(ARDUINO_M5Stack_Tough)
// Values used when M5StickC, M5STickCPlus or M5Stick_C_Plus2 environment is selected:
#define RX_PIN    36// Pin connected to the TX pin of X10A 
#define TX_PIN    26// Pin connected to the RX pin of X10A
#else 
//Default GPIO PINs for Serial2:
#define RX_PIN    16// Pin connected to the TX pin of X10A 
#define TX_PIN    17// Pin connected to the RX pin of X10A
#endif

#define PIN_THERM 0// Pin connected to the thermostat relay (normally open)
#define PIN_THERM_ACTIVE_STATE HIGH// State to trigger the thermostat relay

//Smart grid control - Optional:
//Uncomment and set to enable SG mqtt functions
//#define PIN_SG1 32// Pin connected to dry contact SG 1 relay (normally open)
//#define PIN_SG2 33// Pin connected to dry contact SG 2 relay (normally open)
// Define if your SG relay board is Low or High triggered (signal pins)
// Only uncomment one of them
#define SG_RELAY_HIGH_TRIGGER
//#define SG_RELAY_LOW_TRIGGER

// Safety relay - also called Prefered electric fare - Optional
// If the safety relay is triggered, the heat pump will be stopped
// uncomment and set to enable the safety relay
// #define SAFETY_RELAY_PIN 33// Pin connected to the safety relay
// #define SAFETY_RELAY_ACTIVE_STATE HIGH// Pin connected to the safety relay


// DO NOT CHANGE: Defines the SG active/inactive relay states, according to the definition of the trigger status
#if defined(SG_RELAY_LOW_TRIGGER)
#define SG_RELAY_ACTIVE_STATE LOW
#define SG_RELAY_INACTIVE_STATE HIGH
#else
#define SG_RELAY_ACTIVE_STATE HIGH
#define SG_RELAY_INACTIVE_STATE LOW
#endif

#define MAX_MSG_SIZE 7120//max size of the json message sent in mqtt 

//Uncomment this line if the JSON message should be in a Json Table format []. Use only for IOBroker Vis. 
//#define JSONTABLE

//Uncomment this if you want to activate the One Value <-> One Topic mode. Each value will be sent to a specific topic below 
// #define ONEVAL_ONETOPIC
// #define MQTT_OneTopic "espaltherma/OneATTR/" //Keep the ending "/" !!

//Uncomment to disable common frequent log messages via MQTT to reduce network load
#define DISABLE_LOG_MESSAGES

//Uncomment this line to enable DebugSerial - MQTT<>Serial gateway functionality
//Messages received on espaltherma/serialTX are sent to serial port
//Responses from serial port are published to espaltherma/serialRX
//#define DEBUG_SERIAL

//Then, open and edit the selected file in the /include/def/ folder and uncomment each values you are interested in.
#include "def/Altherma(LT_EBLQ-EBLQ-CA series 5-7kW Monobloc).h"


#ifndef LABELDEF
#warning "NO DEFINITION SELECTED: Please select your heat pump definition in /src/setup.h -- Using default."
#include "def/DEFAULT.h"
#endif

// Default to "Protocol I"
#ifndef PROTOCOL
#define PROTOCOL 'I'
#endif
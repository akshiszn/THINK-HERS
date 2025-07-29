 VOCO – Smart Home Control for Accessible Living 
 
 VOCO is a smart switch system built using ESP32 that enables people with disabilities and the elderly to control home appliances through voice commands. 
 It ensures accessibility with a limited internet connection. VOCO is designed to be affordable, scalable, and inclusive.

🔧 Features

Voice-based appliance control

Works with limited internet connection

Mobile app designed in Figma (Flutter UI)

Controls 4-8 appliances using relays

Easy to expand for full smart home setup

🛠 Tech Stack

Microcontroller: ESP32

Communication: HTTP Web Server

App: Flutter (UI prototyped in Figma)

Voice Module (For further integration): Elechouse V3

Platform: Arduino IDE

->>> How It Works

The user speaks a voice command through our app.

The app sends this command over Wi-Fi to the ESP32 microcontroller.

The ESP32 processes the input and triggers the relay to turn the appliance ON or OFF.

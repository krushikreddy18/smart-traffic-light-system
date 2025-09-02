# SIP Smart Traffic Light System

## Project Overview

The **Smart Traffic Light System** is designed to manage traffic efficiently across three intersections using real-time vehicle detection. This system leverages **infrared (IR) sensors** to detect vehicle presence, dynamically adjusting traffic light priorities based on traffic volume at each intersection. The goal is to minimize traffic congestion and improve traffic flow.


## Features

- **Real-time Traffic Monitoring**: Uses IR sensors to detect vehicles.
- **Dynamic Traffic Light Adjustment**: Traffic light timings are adjusted based on vehicle counts at each intersection.
- **Efficient Traffic Flow**: Reduces congestion by assigning traffic light priority according to real-time traffic conditions.

## Components

1. **Infrared (IR) Sensors**: Used to detect vehicle presence at intersections.
2. **Traffic Light Module**: Consists of red, yellow, and green LEDs, controlled dynamically to manage traffic.
3. **Microcontroller**: Manages input from sensors and controls traffic light operations.
4. **Power Supply**: Powers the system components.

## Working Principle

1. **Infrared Sensors (IR)**: These sensors detect vehicles at each intersection by emitting and receiving infrared radiation.
2. **Traffic Light Module**: The traffic lights (red, yellow, and green LEDs) are controlled to adjust traffic flow based on vehicle detection.
3. **Dynamic Priority Adjustment**: Based on the vehicle count at each intersection, the system dynamically changes the light duration to prioritize congested lanes.

## Circuit Diagram

A schematic view of the circuit diagram shows the connections between the IR sensors, traffic light module, and microcontroller.

## Output

The hardware output includes the control of the traffic light module to manage traffic flow based on real-time data from the sensors.

---

## Installation

1. Assemble the hardware components as per the circuit diagram.
2. Upload the microcontroller code to control the sensors and traffic lights.
3. Power the system and monitor traffic at the three intersections.

---

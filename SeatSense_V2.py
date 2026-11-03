from microbit import *

# SeatSense V2
# Multi-level pressure prototype

pressure = 0

light_threshold = 30
occupied_threshold = 60

status = "EMPTY"

while True:

    # Button A simulates increasing pressure
    if button_a.was_pressed():
        pressure = pressure + 20

        # Keep the simulated pressure within 0-100
        if pressure > 100:
            pressure = 100

    # Button B resets the seat to empty
    if button_b.was_pressed():
        pressure = 0

    # Classify the pressure into three seat states
    if pressure >= occupied_threshold:
        status = "OCCUPIED"

    elif pressure >= light_threshold:
        status = "LIGHT"

    else:
        status = "EMPTY"

    # Display the current seat state
    if status == "OCCUPIED":
        display.show(Image.NO)

    elif status == "LIGHT":
        display.show(Image.DIAMOND)

    else:
        display.show(Image.YES)

    sleep(200)

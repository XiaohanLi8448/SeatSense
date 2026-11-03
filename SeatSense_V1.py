from microbit import *

# SeatSense V1
# Simulated pressure sensor prototype

pressure = 0
threshold = 50
occupied = False

display.scroll("SEAT")

while True:

    # Button A simulates someone sitting on the seat
    if button_a.was_pressed():
        pressure = 80

    # Button B simulates the seat becoming empty
    if button_b.was_pressed():
        pressure = 10

    # Check whether the seat is occupied
    if pressure >= threshold:
        occupied = True
    else:
        occupied = False

    # Show the seat status
    if occupied:
        display.show(Image.NO)
    else:
        display.show(Image.YES)

    sleep(200)

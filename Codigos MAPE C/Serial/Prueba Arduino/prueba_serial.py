import serial
import time

USB_port = 'COM3'

ser = serial.Serial()
ser.port = USB_port

def loop():
    print('Port', USB_port, 'open:', ser.is_open)
    if not ser.is_open:
        print(USB_port, 'is not open. Attempting to open...')

        """
        if ser.open():
            print('Success')
        else:
            print('Could not open', USB_port)
            return
        """
        print("Error:",ser.open())
    else:
        ser.write('hello world!')
        ser.read_until()

while True:
    loop()
    time.sleep(1)

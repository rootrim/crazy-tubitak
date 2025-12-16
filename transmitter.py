# don't forget to install the library with "pip install pyserial" or "sudo apt install python3-serial"
import serial

ser = serial.Serial(
    port='/dev/serial0',
    baudrate=9600,
    timeout=1
)

while True:
    # Writing this with b"" is crucial!!! 'Cause this is a byte literal not a fucking string
    ser.write(b"hello from raspberry\n")

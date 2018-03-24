import sys
import time
import serial
#http://pyserial.readthedocs.io/en/latest/shortintro.html


ser = serial.Serial('COM8', 9600, timeout=2)   #('/dev/ttyUSB0') ('/dev/ttyS1')  # open serial port
print(ser.name)         # check which port was really used

def Send(serial_send):
    print('Send')
    ser.write(serial_send)     # write a string


def Read():
    print('Read')
    line = ser.readline()
    print(line)


def Loop(serial_send): #send something the read something
    for num in range(1,10):
        sendappend = serial_send + str(num)
        Send(sendappend)
        Read()
        time.sleep(1)

def End():
    print('End')
    ser.close()
    sys.exit()

if __name__ == "__main__":
    Send('Hello')
    

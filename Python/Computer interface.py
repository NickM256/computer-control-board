import serial
#http://pyserial.readthedocs.io/en/latest/shortintro.html

#ser = serial.Serial('COM3')   #('/dev/ttyUSB0')  # open serial port
#print(ser.name)         # check which port was really used
#ser.write(b'hello')     # write a string
#ser.close()             # close port


ser = serial.Serial('COM3', 9600)   #('/dev/ttyUSB0')  # open serial port
print(ser.name)         # check which port was really used

def Send(serial_send):
    #ser.open()             # close port
    ser.write(serial_send)     # write a string
    #ser.close()             # close port
    line = ser.readline()   # read a '\n' terminated line
    print(line)

if __name__ == "__main__":
    SendSer('Hello')
    

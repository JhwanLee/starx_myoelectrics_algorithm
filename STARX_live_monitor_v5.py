#Jaehwan Lee, Ocober 2016

import matplotlib.pyplot as plt
import numpy as np
import serial
import sys
import time

def connect():
    #try to connect
    try:
        print ("Connecting Arduino")
        ard = serial.Serial('COM6', 115200)  #replace with whatever USB port
        time.sleep(2)
    except:
        print ("Shit's really fucked") #means arduino connection error
        #sys.exit(1)
    print ("Connected.")
    return ard

startTime = time.time() #For real time graph

#Data Storage
Data = ''
inChar = ''

t = startTime-time.time() #Time since start

plt.figure() #Creating Figure
plt.ylabel("Angle", fontsize=20)
plt.xlabel("Time", fontsize=20)
plt.grid(True)
plt.axis([0, 15, 0, 1000]) # Axis Ranges
plt.ion() #interactive mode on
line, = plt.plot([], [])
plt.show(block=False) #Show graph

ard = connect() #Connect to arduino
print ("what happened")
ard.reset_input_buffer()
#graphing
while True:
    ard.reset_input_buffer()
    inChar = ''
    while not(inChar == '\n'):
        inChar = ard.read()
    t = time.time() - startTime #keeping track of time
    inChar = ''
    while not(inChar == '\n'):
        Data += inChar
        inChar = ard.read()
    line.set_xdata(np.append(line.get_xdata(), t))
    line.set_ydata(np.append(line.get_ydata(), float(Data)))
    plt.draw()
    Data = '' #clear var Data
    if t>15: #Axis Reset
        plt.cla() #clear axis
        plt.axis([0, 15, 0, 1000]) #Resetting the axis
        plt.grid(True)
        plt.ylabel("Angle", fontsize=20)
        plt.xlabel("Time", fontsize=20)
        line, = plt.plot([], []) #Resetting the line
        startTime = time.time() #go back to time 0
    plt.pause(0.05)

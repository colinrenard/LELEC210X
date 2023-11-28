# -*- coding: utf-8 -*-
"""
uart-reader.py
ELEC PROJECT - 210x
"""
import argparse

import matplotlib.pyplot as plt
import numpy as np
import serial
import soundfile as sf
from serial.tools import list_ports

PRINT_PREFIX = "SND:HEX:"
FREQ_SAMPLING = 10200
VAL_MAX_ADC = 4096
VDD = 3.3


def parse_buffer(line):
    line = line.strip()
    if line.startswith(PRINT_PREFIX):
        return bytes.fromhex(line[len(PRINT_PREFIX) :])
    else:
        print(line)
        return None


def reader(port=None):
    ser = serial.Serial(port=port, baudrate=115200)
    while True:
        line = ""
        while not line.endswith("\n"):
            line += ser.read_until(b"\n", size=1042).decode("ascii")
        line = line.strip()
        buffer = parse_buffer(line)
        if buffer is not None:
            dt = np.dtype(np.uint16)
            dt = dt.newbyteorder("<")
            buffer_array = np.frombuffer(buffer, dtype=dt)

            yield buffer_array


def generate_audio(buf, file_name):
    buf = np.asarray(buf, dtype=np.float64)
    buf = buf - np.mean(buf)
    buf /= max(abs(buf))
    sf.write("audio_files/" + file_name + ".ogg", buf, FREQ_SAMPLING)


if __name__ == "__main__":
    argParser = argparse.ArgumentParser()
    argParser.add_argument("-p", "--port", help="Port for serial communication")
    args = argParser.parse_args()
    print("uart-reader launched...\n")

    if args.port is None:
        print(
            "No port specified, here is a list of serial communication port available"
        )
        print("================")
        port = list(list_ports.comports())
        for p in port:
            print(p.device)
        print("================")
        print("Launch this script with [-p PORT_REF] to access the communication port")

    else:
        plt.figure(figsize=(10, 5))
        input_stream = reader(port=args.port)
        msg_counter = 0

        for msg in input_stream:
            print("Acquisition #{}".format(msg_counter))

            buffer_size = len(msg)
            times = np.linspace(0, buffer_size - 1, buffer_size) * 1 / FREQ_SAMPLING
            voltage_mV = msg * VDD / VAL_MAX_ADC * 1e3

            plt.plot(times, voltage_mV)
            plt.title("Acquisition #{}".format(msg_counter))
            plt.xlabel("Time (s)")
            plt.ylabel("Voltage (mV)")
            plt.ylim([0, 3300])
            plt.draw()
            plt.pause(0.001)
            plt.savefig('audio_files/acq-{}.pdf'.format(msg_counter))
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
            #plt.show()
<<<<<<< HEAD
=======
=======
>>>>>>> 1e441ad (avancement sans colin 🚀)
=======
>>>>>>> 556d07c (avancement sans colin 🚀)
            plt.cla()
>>>>>>> 704a8bb (avancement sans colin 🚀)
=======
            #plt.show()
>>>>>>> 1d7321c (fin h2b 🏄)
=======
            plt.cla()
>>>>>>> e65878e (avancement sans colin 🚀)
=======
            #plt.show()
>>>>>>> f377759 (fin h2b 🏄)
=======
            #plt.show()
>>>>>>> 754b14e (fin h2b 🏄)
=======
            #plt.show()
>>>>>>> 7bcd62f (fin h2b 🏄)
=======
            #plt.show()
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
=======
            plt.cla()
>>>>>>> ae514d0 (avancement sans colin 🚀)
            
            # print(msg)
            generate_audio(msg, 'acq-{}'.format(msg_counter))

            plt.figure()
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV)))
            plt.plot(fft)
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
<<<<<<< HEAD
<<<<<<< HEAD
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
=======
            plt.cla()
=======
            #plt.show()
>>>>>>> ae4cc29 (fin h2b 🏄)
            
            # print(msg)
            generate_audio(msg, 'acq-{}'.format(msg_counter))
            
            plt.figure()

            fs = 32e6/(16*195)
            print(fs)
            frequency_axis = np.fft.fftshift(np.fft.fftfreq(len(voltage_mV), 1.0 / fs))
            fft = np.abs(np.fft.fftshift(np.fft.fft(voltage_mV-np.mean(voltage_mV))))
            plt.plot(frequency_axis, fft, label="FFT")
            plt.savefig('audio_files/fftt-acq-{}.pdf'.format(msg_counter))
<<<<<<< HEAD
            plt.cla()
>>>>>>> a568686 (avancement sans colin 🚀)
=======
            plt.xlabel(r'f[Hz]')
            plt.legend()
            plt.show()
            #plt.cla()
>>>>>>> ae4cc29 (fin h2b 🏄)
            
=======
>>>>>>> 097599e (ffft multiple)
=======
>>>>>>> e9d869fc335fa1630213bb1270206efea7efbfa6
            msg_counter+=1

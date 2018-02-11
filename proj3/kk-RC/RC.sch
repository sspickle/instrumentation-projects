EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R1
U 1 1 5A7F1984
P 3900 2450
F 0 "R1" V 3980 2450 50  0000 C CNN
F 1 "?" V 3900 2450 50  0000 C CNN
F 2 "" V 3830 2450 50  0001 C CNN
F 3 "" H 3900 2450 50  0001 C CNN
	1    3900 2450
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 5A7F19DD
P 4200 2850
F 0 "C1" H 4225 2950 50  0000 L CNN
F 1 "?" H 4225 2750 50  0000 L CNN
F 2 "" H 4238 2700 50  0001 C CNN
F 3 "" H 4200 2850 50  0001 C CNN
	1    4200 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2450 5100 2450
Wire Wire Line
	4200 2450 4200 2700
$Comp
L GND #PWR1
U 1 1 5A7F1A07
P 4200 3150
F 0 "#PWR1" H 4200 2900 50  0001 C CNN
F 1 "GND" H 4200 3000 50  0000 C CNN
F 2 "" H 4200 3150 50  0001 C CNN
F 3 "" H 4200 3150 50  0001 C CNN
	1    4200 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3150 4200 3000
Text GLabel 3350 2450 0    60   Input ~ 0
VIn
Text GLabel 5100 2450 2    60   Input ~ 0
Vout
Wire Wire Line
	3350 2450 3750 2450
Connection ~ 4200 2450
$EndSCHEMATC

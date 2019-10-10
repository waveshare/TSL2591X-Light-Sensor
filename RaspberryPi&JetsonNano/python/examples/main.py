import time
import sys
import os

libdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'lib')
if os.path.exists(libdir):
    sys.path.append(libdir)

import logging
from waveshare_TSL2591 import TSL2591

logging.basicConfig(level=logging.INFO)

sensor = TSL2591.TSL2591()
# sensor.SET_InterruptThreshold(0xff00, 0x0010)
try:
    while True:
        lux = sensor.Lux
        print('Lux: %d'%lux)
        sensor.TSL2591_SET_LuxInterrupt(50, 200)
        infrared = sensor.Read_Infrared
        print('Infrared light: %d'%infrared)
        visible = sensor.Read_Visible
        print('Visible light: %d'%visible)
        full_spectrum = sensor.Read_FullSpectrum
        print('Full spectrum (IR + visible) light: %d\r\n'%full_spectrum)
    
except KeyboardInterrupt:    
    logging.info("ctrl + c:")
    sensor.Disable()
    exit()


import serial
import plotly.plotly as py
import plotly.graph_objs as go

port = serial.Serial('/dev/cu.usbserial-DN04AX6V')   # open the serial port (MAC/Linux)

chars = []
vals = []

while 1:
    c = port.read()
    if c==b'\n':
        val = ''.join(chars).strip()
        chars = []
        vals.append(float(val))
        print(val)
    else:
        chars.append(c.decode('utf-8'))

    if len(vals)>100:

        trace0 = go.Scatter(x=list(range(len(vals))), y=vals )
        data = [trace0]

        py.plot(data, filename = 'range-data', auto_open=False)
        vals = []

port.close()                            # shut it down



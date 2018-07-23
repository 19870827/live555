./genMakefiles armlinux
testRTSPClient rtsp://192.168.1.168/0
h265 SENDMAX=1400bytes udp  sendto 127.0.0.1:54321  

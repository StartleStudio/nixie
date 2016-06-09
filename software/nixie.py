import serial
ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=4)
class nixie:
	address = 255
	def __init__(self,address = 255):
		self.address = address
	def scan(self):
		ser.write("NIX,SCAN\r\n")
		dat = ser.readline()
		print dat
	def on(self):
		ser.write("NIX,"+str('%03d' %self.address)+",ON\r\n")
		dat = ser.readline()
		print dat
	def off(self):
		ser.write("NIX,"+str('%03d' %self.address)+",OFF\r\n")
		dat = ser.readline()
		print dat
	def status(self):
		ser.write("NIX,"+str('%03d' %self.address)+",STATUS\r\n")
		dat = ser.readline()
		print dat
	def firmware(self):
		ser.write("NIX,"+str('%03d' %self.address)+",FW\r\n")
		dat = ser.readline()
		print dat
	def change_addr(self,new_address):
		self.new_address = new_address
		ser.write("NIX,"+str('%03d' %self.address)+",CHGADDR,"+str('%03d' %self.new_address)+",\r\n")
		dat = ser.readline()
		print dat
	def setpos(self,pos = 0):
		self.pos = pos
		ser.write("NIX,"+str('%03d' %self.address)+",SETPOS,"+str('%02d' %self.pos)+"\r\n")
		dat = ser.readline()
		print dat
	def getpos(self):
		ser.write("NIX,"+str('%03d' %self.address)+",GETPOS\r\n")
		dat = ser.readline()
		print dat
		
if __name__ == "__main__":		
	nix = nixie()
	nix.firmware()
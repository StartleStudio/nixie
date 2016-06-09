import nixie
import time

nix = nixie.nixie(255) # Default address is 255
nix.scan() # Returns the address of the nxie controler
nix.status() # Checks the status of the controller. Returns 'OK' if active
nix.firmware() # Returns the firmware version
nix.setpos() # Sets the position of the nixie. Position number is passed as attribute. Default is 0
nix.getpos() # Returns the position of the nixie
nix.on() # Powers on the nixie
#nix.off() # Powers off the nixie
#nix.change_addr(215) # Changes the nixie address to the value specified.

for i in range(0,10):
	nix.setpos(i)
	time.sleep(0.1)
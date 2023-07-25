# SETTING UP THE PIUMA SDV [INTEL CONFIDENTIAL]

Once the SDV has been set up per the (Physical Assembly)[https://drive.google.com/file/d/11pyErG-NWkQfhW5SHwAsw4l9TfJNbV7Y/view?usp=drive_link] and (Network Topology)[https://drive.google.com/file/d/1qp9n3qxSt4a4JoJnaonERoSBjLatzuat/view?usp=drive_link] instructions, I used the (How-To Video)[https://drive.google.com/file/d/1SSXAHJjvSPf-L5qHTElnKz_SpSgD7GBv/view?usp=drive_link] to generate the following:

**NOTE: WATCHING THE TUTORIAL VIDEO IS MANDATORY PRIOR TO PROCEEDING**

1 -  SSH into the PiUMA NUC

	tbc with network config

2 - Once in the PiUMA NUC, SSH into the PiUMA Host, relaying through the NUC:

	ssh piuma-host

3 - To figure out the current version of PiUMA, in the PiUMA host run the following command and look for the numeric value in the target of the symbolic link it returns. The link will be something like *intel-piuma-software-env.sh -> /opt/intel/piuma/**dev.40**/intel_piuma_env.sh*. The Bold part of the above is the version. 

	ll /etc/profile.d | grep piuma

4 - We can then check the environment variables with the command:

	env | grep PIUMA

5 - To check other versions use:

	ll /opt/intel/piuma

6 - To see what is inside the distribution use: 

	ll /opt/intel/piuma/**version_here**

7 - We can check the available datasets, spread across two locations using: 

	ll /opt/HIVE-Datasets
	ll /opt/HIVE-Workflows

8 - We can of course then see the contents of any of the datasets with

	ll /opt/HIVE-Workflows/**dataset_name**

The main way they load data is with binary files. For the most part they are graphs in the CSR format, packaged as binary files. 

9 - To run the basic functionality test use: 

	cd /home/piuma/**piuma-toolkit-version**/examples/hello
	make install
	make run
	make qcons

# Setting up the Linux Environment for our testing




## System Setup
See the setup_Ubuntu.sh file for all commands used to set up the system for profiling and running GPUs

## User Setup
See the makeUser.sh file which can be run as the root user on the server to create new users. 

To create a new user you need their public key, to get the user to generate their public key do: 

so, we will be accessing the server through SSH, and I need you both to create SSH key pairs. We can talk about how the cryptography works some time, but basically we are generating a PUBLIC key (i.e. one that everyone can know) and a PRIVATE key (i.e. one that only you should know)

 I'll show you the commands I used, and you can set your own usernames accordingly. I did this on my desktop but you can do it anywhere.

	//generate the Key pair.
	ssh-keygen -m PEM -t rsa -b 4096

It will prompt for a file name, i went with osullik_mn
It will prompt you for a password. You of course should set a password, but if you choose not to I won't tell anyone & it'll prompt you for it every time you log in.
It will generate two files for you

	osullik_mn
	osullik_mn.pub

I need you to send me your equivalent of osullik_mn.pub in slack. This is your public key.
You need to keep your equivalent of osullik_mn SECRET, as this is you PRIVATE key that you will use to ssh in to the box.

To that end, let's make it into the customary format

	mv osullik_mn osullik_mn.pem
	chmod 400 osullik_mn.pem

This is changing the file name to a .pem file, and making it read-only by you.
Once you have sent me your .pub file, I will use it to create your account.
I would then login to my account using the following command (run from the same directory as the .pem file, hence desktop earlier)

	ssh -i osullik_mn.pem osullik@54.84.25.80

here ssh is the program - "start an ssh connection"
-i tells the program that the next argument will be an identity file
osullik_mn.pem is the identity file i just told it to expect
osullik is the username on the server
@54.84.25.80 is the IP address to connect to with that username and identify file

### Uploading to the Server
then if I wanted to transfer files up to the server I'd use something like:

	scp -i osullik_mn.pem test.txt osullik@54.84.25.80:/home/osullik/test/test.txt

Where:
scp is the secure copy program
-i tells the program that the next argument will be an identity file
osullik_mn.pem is the identity file i just told it to expect
test.txt is the file on my local machine I want to copy (needs to be in the same directory you run this command, or you have to fully qualify it)
osullik is the username on the server
@54.84.25.80 is the IP address to connect to with that username and identify file
:/home/osullik/test/test.txt says where in the remote server to put the file

### Git Setup

so, to use github on the server you need to set up an SSH key, to do that, in your home directory on the server do the following, replacing with your details where appropriate:

	ssh-keygen -t ed25519 -C "osullik@protonmail.com"
when prompted, put in:

	~/.ssh/osullik_git

optionally add a passphrase
make sure its there:

	ls ~/.ssh/ | grep osullik_git

you should see something like:

	osullik_git
	osullik_git.pub

We will need your public key in a moment so print it out and copy it to your clipboard:

	cat ~/.etc/osullik_git.pub

To copy it to your clipboard on your mac, just highlight it and use the COMMAND+C shortcut

Add to the SSH agent by first starting it:

	eval "$(ssh-agent -s)"

Then adding it:

	ssh-add ~/.ssh/osullik_git

then you need to add it to your github account.  In your web browser 
go to [Github Keys Page](https://github.com/settings/keys)
then, click on the new ssh key button
name your key something, mine is osullik_minnesota for example
then paste in the content of your equivalent of osullik_git.pub that you copied to your clipboard earlier
save
then you should be good to go!

## System Details: 
The dump of the system that experiments are being run on

### CPUs

	sudo dmidecode

```
# dmidecode 3.3
Getting SMBIOS data from sysfs.
SMBIOS 2.7 present.
87 structures occupying 3575 bytes.
Table at 0x000EB01F.

Handle 0x0000, DMI type 0, 24 bytes
BIOS Information
	Vendor: Xen
	Version: 4.11.amazon
	Release Date: 08/24/2006
	Address: 0xE8000
	Runtime Size: 96 kB
	ROM Size: 64 kB
	Characteristics:
		PCI is supported
		EDD is supported
		Targeted content distribution is supported
	BIOS Revision: 4.11

Handle 0x0100, DMI type 1, 27 bytes
System Information
	Manufacturer: Xen
	Product Name: HVM domU
	Version: 4.11.amazon
	Serial Number: ec2a59ce-6314-efdb-3e42-da23b011c047
	UUID: ec2a59ce-6314-efdb-3e42-da23b011c047
	Wake-up Type: Power Switch
	SKU Number: Not Specified
	Family: Not Specified

Handle 0x0300, DMI type 3, 21 bytes
Chassis Information
	Manufacturer: Xen
	Type: Other
	Lock: Not Present
	Version: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Boot-up State: Safe
	Power Supply State: Safe
	Thermal State: Safe
	Security Status: Unknown
	OEM Information: 0x00000000
	Height: Unspecified
	Number Of Power Cords: Unspecified
	Contained Elements: 0

Handle 0x0401, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 1
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0402, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 2
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0403, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 3
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0404, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 4
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0405, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 5
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0406, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 6
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0407, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 7
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0408, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 8
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0409, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 9
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x040A, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 10
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x040B, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 11
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x040C, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 12
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x040D, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 13
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x040E, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 14
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x040F, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 15
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0410, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 16
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0411, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 17
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0412, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 18
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0413, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 19
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0414, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 20
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0415, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 21
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0416, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 22
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0417, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 23
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0418, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 24
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0419, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 25
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x041A, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 26
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x041B, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 27
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x041C, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 28
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x041D, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 29
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x041E, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 30
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x041F, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 31
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0420, DMI type 4, 35 bytes
Processor Information
	Socket Designation: CPU 32
	Type: Central Processor
	Family: Other
	Manufacturer: Intel
	ID: F1 06 04 00 FF FB 8B 17
	Version: Not Specified
	Voltage: Unknown
	External Clock: Unknown
	Max Speed: 2300 MHz
	Current Speed: 2300 MHz
	Status: Populated, Enabled
	Upgrade: Other
	L1 Cache Handle: Not Provided
	L2 Cache Handle: Not Provided
	L3 Cache Handle: Not Provided
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified

Handle 0x0B00, DMI type 11, 5 bytes
OEM Strings
	String 1: Xen

Handle 0x1000, DMI type 16, 19 bytes
Physical Memory Array
	Location: Other
	Use: System Memory
	Error Correction Type: Multi-bit ECC
	Maximum Capacity: 244 GB
	Error Information Handle: Not Provided
	Number Of Devices: 16

Handle 0x1100, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 0
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1300, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x00000000000
	Ending Address: 0x003FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1400, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x00000000000
	Ending Address: 0x003FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1100
	Memory Array Mapped Address Handle: 0x1300
	Partition Row Position: 1

Handle 0x1101, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 1
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1301, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x00400000000
	Ending Address: 0x007FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1401, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x00400000000
	Ending Address: 0x007FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1101
	Memory Array Mapped Address Handle: 0x1301
	Partition Row Position: 1

Handle 0x1102, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 2
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1302, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x00800000000
	Ending Address: 0x00BFFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1402, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x00800000000
	Ending Address: 0x00BFFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1102
	Memory Array Mapped Address Handle: 0x1302
	Partition Row Position: 1

Handle 0x1103, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 3
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1303, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x00C00000000
	Ending Address: 0x00FFFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1403, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x00C00000000
	Ending Address: 0x00FFFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1103
	Memory Array Mapped Address Handle: 0x1303
	Partition Row Position: 1

Handle 0x1104, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 4
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1304, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x01000000000
	Ending Address: 0x013FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1404, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x01000000000
	Ending Address: 0x013FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1104
	Memory Array Mapped Address Handle: 0x1304
	Partition Row Position: 1

Handle 0x1105, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 5
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1305, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x01400000000
	Ending Address: 0x017FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1405, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x01400000000
	Ending Address: 0x017FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1105
	Memory Array Mapped Address Handle: 0x1305
	Partition Row Position: 1

Handle 0x1106, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 6
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1306, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x01800000000
	Ending Address: 0x01BFFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1406, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x01800000000
	Ending Address: 0x01BFFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1106
	Memory Array Mapped Address Handle: 0x1306
	Partition Row Position: 1

Handle 0x1107, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 7
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1307, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x01C00000000
	Ending Address: 0x01FFFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1407, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x01C00000000
	Ending Address: 0x01FFFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1107
	Memory Array Mapped Address Handle: 0x1307
	Partition Row Position: 1

Handle 0x1108, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 8
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1308, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x02000000000
	Ending Address: 0x023FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1408, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x02000000000
	Ending Address: 0x023FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1108
	Memory Array Mapped Address Handle: 0x1308
	Partition Row Position: 1

Handle 0x1109, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 9
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x1309, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x02400000000
	Ending Address: 0x027FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x1409, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x02400000000
	Ending Address: 0x027FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x1109
	Memory Array Mapped Address Handle: 0x1309
	Partition Row Position: 1

Handle 0x110A, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 10
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x130A, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x02800000000
	Ending Address: 0x02BFFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x140A, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x02800000000
	Ending Address: 0x02BFFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x110A
	Memory Array Mapped Address Handle: 0x130A
	Partition Row Position: 1

Handle 0x110B, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 11
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x130B, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x02C00000000
	Ending Address: 0x02FFFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x140B, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x02C00000000
	Ending Address: 0x02FFFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x110B
	Memory Array Mapped Address Handle: 0x130B
	Partition Row Position: 1

Handle 0x110C, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 12
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x130C, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x03000000000
	Ending Address: 0x033FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x140C, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x03000000000
	Ending Address: 0x033FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x110C
	Memory Array Mapped Address Handle: 0x130C
	Partition Row Position: 1

Handle 0x110D, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 13
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x130D, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x03400000000
	Ending Address: 0x037FFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x140D, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x03400000000
	Ending Address: 0x037FFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x110D
	Memory Array Mapped Address Handle: 0x130D
	Partition Row Position: 1

Handle 0x110E, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 16 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 14
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x130E, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x03800000000
	Ending Address: 0x03BFFFFFFFF
	Range Size: 16 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x140E, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x03800000000
	Ending Address: 0x03BFFFFFFFF
	Range Size: 16 GB
	Physical Device Handle: 0x110E
	Memory Array Mapped Address Handle: 0x130E
	Partition Row Position: 1

Handle 0x110F, DMI type 17, 34 bytes
Memory Device
	Array Handle: 0x1000
	Error Information Handle: 0x0000
	Total Width: 64 bits
	Data Width: 64 bits
	Size: 4 GB
	Form Factor: DIMM
	Set: None
	Locator: DIMM 15
	Bank Locator: Not Specified
	Type: RAM
	Type Detail: None
	Speed: Unknown
	Manufacturer: Not Specified
	Serial Number: Not Specified
	Asset Tag: Not Specified
	Part Number: Not Specified
	Rank: Unknown
	Configured Memory Speed: Unknown

Handle 0x130F, DMI type 19, 31 bytes
Memory Array Mapped Address
	Starting Address: 0x03C00000000
	Ending Address: 0x03CFFFFFFFF
	Range Size: 4 GB
	Physical Array Handle: 0x1000
	Partition Width: 1

Handle 0x140F, DMI type 20, 35 bytes
Memory Device Mapped Address
	Starting Address: 0x03C00000000
	Ending Address: 0x03CFFFFFFFF
	Range Size: 4 GB
	Physical Device Handle: 0x110F
	Memory Array Mapped Address Handle: 0x130F
	Partition Row Position: 1

Handle 0x2000, DMI type 32, 11 bytes
System Boot Information
	Status: No errors detected

Handle 0x7F00, DMI type 127, 4 bytes
End Of Table

```

### GPUs

	nvidia-smi

```
+---------------------------------------------------------------------------------------+
| NVIDIA-SMI 535.54.03              Driver Version: 535.54.03    CUDA Version: 12.2     |
|-----------------------------------------+----------------------+----------------------+
| GPU  Name                 Persistence-M | Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp   Perf          Pwr:Usage/Cap |         Memory-Usage | GPU-Util  Compute M. |
|                                         |                      |               MIG M. |
|=========================================+======================+======================|
|   0  Tesla M60                      On  | 00000000:00:1D.0 Off |                    0 |
| N/A   29C    P8              14W / 150W |      0MiB /  7680MiB |      0%      Default |
|                                         |                      |                  N/A |
+-----------------------------------------+----------------------+----------------------+
|   1  Tesla M60                      On  | 00000000:00:1E.0 Off |                    0 |
| N/A   34C    P8              15W / 150W |      0MiB /  7680MiB |      0%      Default |
|                                         |                      |                  N/A |
+-----------------------------------------+----------------------+----------------------+
```
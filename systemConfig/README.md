# Setting up the Linux Environment for our testing

## System Details: 


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
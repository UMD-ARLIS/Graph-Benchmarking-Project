#Original Author: Pete Loates
username="$1"
#NOTE: Change this list as appropriate for a project
grouplist="minnesota"

if [ -z $1 ]; then
        echo "Usage $0 <username>"
        exit 1
fi

if [ $EUID -ne 0 ]; then
        echo "Must run using sudo"
        echo "$Usage: $0 <username>"
        exit 1
fi

read -p  "Enter the RSA Public Key " publickey

if [[ -z $publickey ]]; then
    echo "Did not enter the public key"
        exit 1
fi

echo "Creating user for $username"
useradd -m -U -G $grouplist $username
echo "Using public key: $publickey"
homedir="/home/$username"
sshdir="$homedir/.ssh"
authorized_keys="$sshdir/authorized_keys"
echo "Creating SSH directory $sshdir"
mkdir -p $sshdir
echo "Creating $authorized_keys"
touch $authorized_keys

printf "%s" "$publickey" > $authorized_keys
chmod 600 $authorized_keys
chown $username:$username -R $sshdir
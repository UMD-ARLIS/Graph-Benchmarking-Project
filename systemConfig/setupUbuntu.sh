#To Set Up Perf (run with "perf"):
sudo apt install linux-tools-common
sudo apt install linux-tools-5.19.0-1025-aws

#Valgrind (run with "valgrind"): 
sudo apt  install valgrind

#Oprofile (run with "operf"): 
sudo apt install oprofile

#VTUNE (run with "vTune" - note, may need an AWS Metal Instance for full function):
cd /tmp
wget https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB
sudo apt-key add GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB
rm GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB
echo "deb https://apt.repos.intel.com/oneapi all main" | sudo tee /etc/apt/sources.list.d/oneAPI.list
sudo apt update
sudo apt install intel-oneapi-vtune
cd /opt/intel/oneapi/vtune/2023.1.0/sepdk/src
sudo ./build-driver -ni --c-compiler=x86_64-linux-gnu-gcc

source /opt/intel/oneapi/setvars.sh

#HPCToolkit

sudo apt install gcc
sudo apt install g++
sudo apt install gfortran
sudo apt install glibc-source
sudo apt install cmake
sudo apt install perl
sudo apt install git
sudo apt install curl
sudo apt install default-jre
sudo apt install libgtk-3-dev
sudo apt-get install aptitude

git clone https://github.com/spack/spack.git
git clone https://gitlab.com/hpctoolkit/hpctoolkit.git

sh /home/ubuntu/spack/share/spack/setup-env.sh
export PATH="$HOME/spack/bin:$PATH"
spack compiler find
    #Manually verify that both lists of compilers point to the installed versions
    #Update both to point at the correct version of g++ ie 12.1.0
export SPACK_PYTHON=/usr/bin/python3.10

spack install hpctoolkit
spack install hpctoolkit +cuda
PATH=$PATH:/home/ubuntu/spack/opt/spack/linux-ubuntu22.04-broadwell/gcc-12.1.0/hpctoolkit-2023.03.01-uwgqabsfbarmibgqvgfpr7sn6p2ujm3c/bin

#CUDA TOOLKIT
    # Derived from: https://docs.nvidia.com/cuda/cuda-quick-start-guide/index.html#ubuntu

sudo dpkg --install cuda-repo-<distro>-<version>.<architecture>.deb
sudo apt-key del 7fa2af80
wget https://developer.download.nvidia.com/compute/cuda/repos/$distro/$arch/cuda-keyring_1.0-1_all.deb
sudo dpkg -i cuda-keyring_1.0-1_all.deb
sudo add-apt-repository contrib
sudo apt-get update
sudo apt-get -y install cuda

sudo reboot

export PATH=/usr/local/cuda-12.2/bin${PATH:+:${PATH}}
export LD_LIBRARY_PATH=/usr/local/cuda-12.2/lib64\
                         ${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}

git clone https://github.com/NVIDIA/cuda-samples.git #Run from where you want the samples to be located. 
cd cuda_samples
make


#sudo apt install libnvidia-compute-495
sudo apt install libnvidia-compute-525
tmux
sudo apt install nvidia-cuda-toolkit
    # crtl+b d (detach from the tmux session)


##### DID NOT COMPLETE BELOW INSTALLATION - NEED TO UNINSTALL THE FOLLOWING #####
# Xed (Sniper Sim Dependency)
sudo apt install meson
sudo apt install cmake
sudo apt install libglib2.0-dev
sudo apt install build-essential libgtk-3-dev
sudo apt install libgtksourceview-4-dev
sudo apt install libpeas-dev
sudo apt install libxapp-dev
sudo apt install libgspell-1-dev
sudo apt install intltool
sudo apt install itstool
meson --prefix=/usr build
ninja -v -C build
sudo ninja install -v -C build

#Sniper Sim [ABANDONED]
wget http://snipersim.org/download/3bb82bf4fa98c047/packages/sniper-latest.tgz
tar -xf sniper-latest.tgz
rm sniper-latest.tgz 
cd /home/ubuntu/sniper-7.4
sudo apt install python-is-python3
sudo apt install python3-pip
sudo apt install zlib1g-dev
sudo apt install libbz2-dev
sudo apt install libboost-dev
sudo apt install libsqlite3-dev




cd $home
git clone https://github.com/linuxmint/xed.git
cd xed

    #May need to make some edits to python script for print statements etc for make file to run
make all

# media-menu
A simple menu that scrapes YouTube for videos and music and provides access to any anime from your terminal.
# Usage
It's just one command:
```
Menu
```
I am planning to add more features in the future, like an easy way to implement playlists. If you have other ideas, you can submit them as issues and I will do my best to implement them!

**Note**: If you want to change the command, you can change it from the Makefile. Just change the name from ``` PROG ``` to whatever want.
# Installation
**I recommend updating your system first because this script will download all the dependencies from your package manager!**

For Arch Linux based systems:
``` 
git clone https://github.com/hiroi-p/media-menu.git
cd media-menu
sudo make && sudo make install 
```
*AUR version comming soon*

For Debian based systems:
```
git clone https://github.com/hiroi-p/media-menu.git
cd media-menu
sudo make && sudo make install 
```
For Fedora and RHEL based systems:

You have to enable the rpm fusion repos first! Check out [this](https://docs.fedoraproject.org/en-US/quick-docs/setup_rpmfusion/) to learn how to do it.
```
git clone https://github.com/hiroi-p/media-menu.git
cd media-menu
sudo make && sudo make install 
```
To add channels in the subscriptions section, create and put the channel urls in the ```~/.configytfzf/subscriptions``` text file.
# Mentions
This program uses [ytfzf](https://github.com/pystardust/ytfzf) and [ani-cli](https://github.com/pystardust/ani-cli), don't forget to check them out!

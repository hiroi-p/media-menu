.PHONY = all clean
PROGYT = ./ytfzf-1.2.0/ytfzf 
PROG= Menu
PREFIX = /usr/bin
DISTRO = $(shell ./distro_check)
COMPARE = pacman
CC = g++
ifeq (${DISTRO}, pacman) 
DISTRO2=@${DISTRO} -Sy --noconfirm fzf mpv vlc jq curl ueberzug git yt-dlp youtube-dl ncurses python python-pip && git clone https://github.com/pystardust/ani-cli.git && cd ani-cli && cp -r ani-cli /bin && cd .. && rm -rf ani-cli	
COMPILE_DEP=${DISTRO} -Sy --noconfirm ncurses gcc
endif
ifeq (${DISTRO}, apt)
DISTRO2= ${DISTRO} update && ${DISTRO} install -y fzf mpv git jq curl python3 python3-pip libncursesw5-dev libjpeg8-dev zlib1g-dev python-dev python3-dev libxtst-dev && python3 -m pip install --upgrade pip && python3 -m pip install --upgrade Pillow && pip3 install ueberzug && pip3 install youtube-dl && git clone https://github.com/pystardust/ani-cli.git && cd ani-cli && cp -r ani-cli /bin && cd .. && rm -rf ani-cli
COMPILE_DEP=${DISTRO} install -y libncurses5-dev g++ gcc libncursesw5-dev
endif
ifeq (${DISTRO}, dnf)
DISTRO2= ${DISTRO} install -y fzf libX11-devel libXext-devel jq curl yt-dlp ncurses python python-pip python3-devel mpv git openssl && python3 -m pip install --upgrade pip && python3 -m pip install --upgrade Pillow && pip3 install ueberzug && pip3 install youtube-dl && git clone https://github.com/pystardust/ani-cli.git && cd ani-cli && cp -r ani-cli /bin && cd .. & rm -rf ani-cli
COMPILE_DEP= ${DISTRO} install ncurses-devel gcc g++
endif
FLAG = -lncurses

all: menu.cpp
	${COMPILE_DEP}
	${CC} menu.cpp -o ${PROG} ${FLAG}
	chmod 755 $(PROGYT)
	mkdir -p ${PREFIX}
	install ${PROGYT} ${PREFIX}/ytfzf	
install:
	cp ${PROG} ${PREFIX}
	${DISTRO2}
uninstall:
	rm -f ${PREFIX}/ytfzf
	rm -f ${PREFIX}/${PROG}
clean: 
	rm ${PROG}



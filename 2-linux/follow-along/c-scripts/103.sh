# .bashrc

# User specific aliases and functions

alias rm='rm -i'
alias cp='cp -i'
alias mv='mv -i'

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

PATH=$PATH:~/avr8-gnu-toolchain-linux_x86_64/bin/:~/avrdude-6.3/

function ls () {
	command ls -l
	}


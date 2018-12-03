#!/usr/bin/env bash

if [ ! -f travis_build/premake5 ]; then
	mkdir -p travis_build
	cd travis_build
	wget https://github.com/premake/premake-core/releases/download/v5.0.0-alpha12/premake-5.0.0-alpha12-src.zip -O premake.zip
	unzip -qq premake.zip
	cd premake-5.0.0-alpha12/build/gmake.unix
	make config=release
	cd ../../..
	mv premake-5.0.0-alpha12/bin/release/premake5 premake5
	cd ..
fi

if [ "$ARCH" == "js" ]; then

	if [ ! -d travis_build/emsdk ]; then
		mkdir -p travis_build
		cd travis_build
		git clone https://github.com/juj/emsdk.git
		cd emsdk

		./emsdk install latest
		./emsdk activate latest

		cd ../..
	fi

	source travis_build/emsdk/emsdk_env.sh

	curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.11/install.sh | bash

	export NVM_DIR="${XDG_CONFIG_HOME/:-$HOME/.}nvm"
	[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh" # This loads nvm

	nvm install node

fi # ARCH == "js"



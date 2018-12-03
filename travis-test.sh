
source travis_build/emsdk/emsdk_env.sh
make -C build config=${CONFIG}_${ARCH}

if [ "$ARCH" == "x64 ]; then
	bin/${CONFIGURATION}_x64/test
fi


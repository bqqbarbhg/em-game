
source travis_build/emsdk/emsdk_env.sh
make -C build config=${CONFIG}_${ARCH}

if [ "$ARCH" == "js" ]; then
	node bin/${CONFIG}_${ARCH}/test.js
else
	bin/${CONFIG}_${ARCH}/test
fi


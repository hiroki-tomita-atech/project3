build:
	g++ Map.cpp Player.cpp CD.cpp main.cpp -o game \
	-I C:/MinGW/include/DXLib \
	-L C:/MinGW/lib/DXLib \
	-DDX_GCC_COMPILE -DDX_NON_INLINE_ASM \
	-lDxLib \
	-lDxUseCLib \
	-lDxDrawFunc \
	-ljpeg \
	-lpng \
	-lzlib \
	-ltiff \
	-ltheora_static \
	-lvorbis_static \
	-lvorbisfile_static \
	-logg_static \
	-lbulletdynamics \
	-lbulletcollision \
	-lbulletmath \
	-lopusfile \
	-lopus \
	-lsilk_common \
	-lcelt

run:
	game.exe
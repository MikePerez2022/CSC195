#pragma once

struct _BuffByte {
	short myByte;
};

struct _Wifi {
	char SSID[51];
	_BuffByte Buffw1;
	char Pswd[51];
	_BuffByte Buffw2;
};

struct _Version {
	short major;
	short minor;
	short revision;
};

struct Config {
	_Version Version;
	_Wifi wifi;
	_BuffByte Buff1;
};
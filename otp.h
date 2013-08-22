/*
 *  Hans - IP over ICMP
 *  Copyright (C) 2009 Friedrich Schöller <friedrich.schoeller@gmail.com>
 *  OTP Addition by Wouter van der Veer <wouter.van.der.veer@topicus.nl>
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  
 */

#include <string>
#include <stdint.h>
#include <iostream>
#include <fstream>

using namespace std;

class Otp{

public:
	Otp(const char *filename,  bool server);
 	~Otp();
	int openOTPFile();
 	long getReadPos(){ return readPos; };
 	long getWritePos(){ return writePos; };
 	int setReadPos(long position) { readPos = position; };
 	int setWritePos(long position){ writePos = position; };
 	int writeEncode(char *buffer);
 	int readDecode(char *buffer);
protected:
 	bool isServer;
 	const char *filename;
 	long readPos;
 	long writePos;
 	fstream otpFD;
 	long filesize;
 };
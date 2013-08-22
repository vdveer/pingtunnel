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

#include "otp.h"
#include "exception.h"
#include "string.h"

#include <algorithm>
#include <vector>
#include <string>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

char * memblockread;
char * memblockwrite;

	Otp::Otp(const char *filenameIN,  bool server){
		filename = filenameIN;
		isServer = server;
		this->openOTPFile();
	}

 	Otp::~Otp(){
 		otpFD.close();
 	}

	int Otp::openOTPFile(){
		this->readPos = 0;
		this->writePos = 0;
		Otp::otpFD.open(filename, ios::in | ios::out | ios::binary | ios::ate );

	  	if (this->otpFD.is_open())
	  	{
	   	 	this->filesize = otpFD.tellg();
	   		this->writeEncode("test");
	   	 	return 0;
	  	}
	  	throw Exception("Failed to open OTPfile");
	  	return -1;
	}

 	int Otp::writeEncode(char *buffer){
 		if(this->readPos+this->writePos > filesize)
 				throw Exception("No more random data, giving up...");
 		if(this->otpFD.is_open()){
 			int size = strlen(buffer);
 			memblockwrite = new char[size];
 			if(this->isServer){
	    		otpFD.seekg(this->writePos, ios::beg);
	    		otpFD.read(memblockwrite, size);
	    		for(int i = 0; i < size; i++){
	    			buffer[i] = buffer[i] ^ memblockwrite[i];
	    		}
    		}
    		else{
    			otpFD.seekg(this->writePos+size, ios::end);
    			otpFD.read(memblockwrite, size);
    			for(int i = 0; i < size; i++){
	    			buffer[i] = buffer[i] ^ memblockwrite[size-i];
	    		}
    		}
 			this->writePos = this->writePos + size;
 			return 0;
 		}// all not working...
 		throw Exception("Failed to read OTPfile, giving up...");	
 	}

 	int Otp::readDecode(char *buffer){
 		if(this->readPos+this->writePos > filesize)
 				throw Exception("No more random data, giving up...");
 		if(this->otpFD.is_open()){
 			int size = strlen(buffer);
 			//magic
 			this->readPos = this->readPos + size;
 			return 0;
 		}
 		throw Exception("Failed to read OTPfile, giving up...");
 	}

 	/*
 	 * bool isServer;
 	 * const char *filename;
 	 * int readPos;
 	 * int writePos;
 	 * int otpFD;
 	 */
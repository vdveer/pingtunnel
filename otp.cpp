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

#include <string>
#include <stdint.h>

	otp::otp(const char *filename,  bool server){

	}

 	otp::~otp(){

 	}

	int openOTPFile(){
		return -1;
	}

 	int writeEncode(char *buffer){
 		return -1;
 	}

 	int readDecode(char *buffer){
 		return -1;
 	}

 	/*
 	 * bool isServer;
 	 * const char *filename;
 	 * int readPos;
 	 * int writePos;
 	 * int otpFD;
 	 */
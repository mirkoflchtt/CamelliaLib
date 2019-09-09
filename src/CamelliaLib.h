///////////////////////////////////////////////
//
// **************************
// ** ENGLISH - 11/08/2015 **
//
// Project: libObfuscate v2.00
// Company: Advanced Embedded Solutions SAGL
//
// THIS IS A FREE SOFTWARE
//
// This software is released under:
//
// * LGPL 3.0: http://www.gnu.org/licenses/lgpl.html
//
// You�re free to copy, distribute and make commercial use
// of this software under the following conditions:
//
// * You have to cite the author (and copyright owner): Advanced Embedded Solutions SAGL
// * You have to provide a link to the author�s Homepage: http://www.embeddedsw.net/libobfuscate.html
//
///////////////////////////////////////////////

#ifndef __CAMELLIA_LIB_H__
#define __CAMELLIA_LIB_H__
#include <stdint.h>

typedef uint8_t				BYTE;

// ** Thread-safe implementation

// ** Camellia cipher
// ** 128bit block size
// ** 128, 192, 256bit key

class Camellia {
public:
	 Camellia( void );
	~Camellia( void );
	
	// n should be either 128, 192, 256, and
	// thus key should be 16, 24, 32 byte array
	bool		setkey ( const BYTE *key, const uint16_t n );

	// 128 bit encryption : p is plaintext buffer, c is cipher text buffer
	// both plaintext and cipher buffers should be 16 bytes min.
	// plaintext and cipher could be the same buffer!
	// in-place encryption is supported.
	bool		encrypt( const BYTE *p, BYTE *c );

	// 128 bit decryption : p is plaintext buffer, c is cipher text buffer
	// both plaintext and cipher buffers should be 16 bytes min.
	// plaintext and cipher could be the same buffer!
	// in-place decryption is supported.
	bool		decrypt( const BYTE *c, BYTE *p );

private:

	BYTE		m_key[272];	// 208 for 128bit key??
	uint16_t	m_key_size;
};
	


#endif		/*__CAMELLIA_LIB_H__*/

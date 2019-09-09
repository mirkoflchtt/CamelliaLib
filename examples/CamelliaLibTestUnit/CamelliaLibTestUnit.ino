/*
  Camellia Library - TestUnit
 
 Demonstrates the use of 128bit Camellia Cipher
 Performing a number of random encription/decription rounds
 generating from time to time a key.
 Tested different key size: 128, 192 and 256 bit
 
*/
#include <CamelliaLib.h> 

#define TEST_SIZE		(2*1024)

size_t failed   = 0;
size_t count    = 0;

static
void fillRandom( BYTE* data, const size_t size )
{
	for ( size_t i=0; i<size; i++ ) {
		data[i] = ( rand()&0xFF );
	}
}

size_t doTest( const int32_t n )
{
	Camellia c;
	
	BYTE key[32];
	BYTE plain_in[16];
	BYTE plain_out[16];
	BYTE* cipher = plain_out;
	
	size_t failed = 0;
	size_t i;

  count += TEST_SIZE;
  
	for ( i=0; i<TEST_SIZE; i++ )
	{
		if ( 0==(i%32) )
		{
      Serial.print("Generating Key #");
      Serial.println(i);
			// Generate random key
			fillRandom( key, sizeof(key) );
			if ( !c.setkey( key, n ) )
				goto early_fail;
		}

		fillRandom( plain_in, sizeof(plain_in) );
		memcpy( plain_out, plain_in, sizeof(plain_in) );
		
		if ( !c.encrypt( plain_out, cipher ) )
			goto early_fail;

		if ( !c.decrypt( cipher, plain_out ) )
			goto early_fail;
		
		failed += ( 0!=memcmp(plain_in, plain_out, sizeof(plain_in)) );
		continue;

early_fail:
		failed++;
	}
	
	return failed;
}

int testUnit00( void )
{
	size_t last		= 0;
	
	srand( analogRead(0) );
	
	if ( (failed=doTest(128))>0 ) {
		Serial.print("Test 128 : failed ");
		Serial.print(failed-last);
		Serial.println(" tests..");
		last = failed;
	}
	if ( (failed=doTest(192))>0 ) {
		Serial.print("Test 192 : failed ");
    Serial.print(failed-last);
    Serial.println(" tests..");
		last = failed;
	}
	if ( (failed=doTest(256))>0 ) {
		Serial.print("Test 256 : failed ");
    Serial.print(failed-last);
    Serial.println(" tests..");
		last = failed;
	}

  if ( failed )
    Serial.print("Camellia Unit Test Done : KO! ( Failed Tests : ");
	else
	  Serial.print("Camellia Unit Test Done : OK! ( Failed Tests : ");
    
  Serial.print(failed);
	Serial.println(" )");
	
	return (int)failed;
}

void setup( ) {
  Serial.begin(9600);
  testUnit00( );
}

void loop( ) {
  Serial.print("Camellia TestUnit Test Completed. Passed ( ");
  Serial.print(count-failed);
  Serial.print("/");
  Serial.print(count);
  Serial.println(" ) Tests.");
  delay(5000);
}

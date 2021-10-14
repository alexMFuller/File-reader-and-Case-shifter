#include "shifter.h"

char shifter(char s){

	unsigned char moved;

	if (( s >= 'a' && s <= 'z' )){
		moved = s-32;
		return moved;
	}
	else if (( s >= 'A' && s <= 'Z')){
		moved = s+32;
		return moved;
	}
	else{
		return s;
	}
	
}
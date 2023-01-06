/*str.h*/
#ifndef STR
#define STR
#define SIZE 10
#define Word_len_Max 15
void Fgetwords(FILE* fin, char word_m[][Word_len_Max], int* w_len);	//get words from file
void sorting_word(char word_m[][Word_len_Max]);	//sorting words
#endif
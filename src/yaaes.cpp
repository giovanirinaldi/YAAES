#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cstring>
#include <cctype>
#include <gtkmm.h>
#include <iostream>
using namespace std;

#include "rijndael.h"

int mul(int x, int y) {
    int r = 0;
    for (;y!=0;y>>=1,x<<=1)
        if (y&1)
            r+=x;
    return r;
}

unsigned char hexValue(unsigned char &hex){
	if (hex >= 48 && hex <= 57){
		return hex - 48;
	}
	else if (toupper(hex) >= 65 && toupper(hex) <= 70){
		return toupper(hex) - 55;
	}
	else{
		return hex;
	}
}

void hexStringToCharString(unsigned char* hexString, int hexStringLen, unsigned  char* charString){
	for (int i = 0; i < hexStringLen; i=i+2){
		charString[i/2] = hexValue(hexString[i]) * 16 + hexValue(hexString[i+1]);
	}
}

Gtk::Window* pWindow = 0;
/*static void on_button_clicked()
{
  if(pDialog)
    pDialog->hide(); //hide() will cause main::run() to end.
}*/

void on_menu_file_quit(){
	if (pWindow){
		pWindow->hide();
	}
}

void on_about_dialog_close(){
	
}

void on_menu_help_about(){
	Gtk::AboutDialog* pAboutDialog;
  	Glib::RefPtr<Gtk::Builder> aboutBuilder = Gtk::Builder::create();
	aboutBuilder->add_from_file("about.glade");
	aboutBuilder->get_widget("aboutDialog", pAboutDialog);
	if (pAboutDialog)
		pAboutDialog->show();
		
}

int main (int argc, char *argv[]){
	/*Gtk::Main kit(argc, argv);

	//Load the GtkBuilder file and instantiate its widgets:
  	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  	try
  	{
    		refBuilder->add_from_file("main.glade");
  	}
  	catch(const Glib::FileError& ex)
  	{
    		std::cerr << "FileError: " << ex.what() << std::endl;
    		return 1;
  	}
  	catch(const Gtk::BuilderError& ex)
  	{
    		std::cerr << "BuilderError: " << ex.what() << std::endl;
    		return 1;
  	}

  	//Get the GtkBuilder-instantiated Dialog:
  	refBuilder->get_widget("mainWindow", pWindow);
  	if(pWindow)
  	{
    		//Get the GtkBuilder-instantiated Button, and connect a signal handler:
    		Gtk::ImageMenuItem* pMenuFileQuit = 0;
    		Gtk::ImageMenuItem* pMenuHelpAbout = 0;
    		refBuilder->get_widget("menu_file_quit", pMenuFileQuit);
    		refBuilder->get_widget("menu_help_about", pMenuHelpAbout);
    		if(pMenuFileQuit)
    		{
      			pMenuFileQuit->signal_activate().connect(sigc::ptr_fun(on_menu_file_quit));
    		}
    		if(pMenuHelpAbout)
    		{
      			pMenuHelpAbout->signal_activate().connect(sigc::ptr_fun(on_menu_help_about));
    		}
    		kit.run(*pWindow);
  	}*/




	Rijndael r(Rijndael::K128, Rijndael::B128);
	//std::string key = "essasenhaehfraca";
	//std::string hBlock = "00112233445566778899aabbccddeeff";
	//546578746F2070617261207465737465";
	char chBlock[65] = "00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff";
	unsigned char cBlock[33];
	hexStringToCharString((unsigned char*)chBlock, 64, cBlock);
	char chKey[33] = "000102030405060708090a0b0c0d0e0f";
	unsigned char cKey[17];
	hexStringToCharString((unsigned char*)chKey, 32, cKey);
	r.makeKey(cKey);	
	r.encrypt(cBlock, 32);
	for (int i = 0; i < 32; i++){
		printf("%x", cBlock[i]);
	}
	printf("\n");
	r.decrypt(cBlock, 32);
	for (int i = 0; i < 32; i++){
		printf("%x", cBlock[i]);
	}
	printf("\n");
//	std::string block = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
	//printf("%d\n", block.length());
	//hexStringToCharString(chBlock, 32, cBlock);	
	//hexStringToCharString((unsigned char*)hBlock.c_str(), hBlock.length(), (unsigned char*)block.c_str());
	//r.makeKey(key.c_str());
	//printf("%d\n", block.length());
	//r.encrypt((unsigned char*)block.c_str());
	/*printf("%d\n", block.length());
	for (int i = 0; i < block.length(); i++){
		printf("%c ", block[i]);
	}*/
//	printf("\n");
//	timeval t1, t2;
/*	char input[1024];
	char ch[Rijndael::K128/8];
	unsigned char uch[Rijndael::K128/8];
	signed char sch[Rijndael::K128/8];*/
//	unsigned char a[5] = "abcd";
//	if (fgets(input, 16+1, stdin)){
//		if (sscanf(input, "%s", uch) == 1){
			//printf("%d\n", a[0]);
//		}
//	}
//	printf("%d\n", a);
//	gettimeofday(&t1, 0);
//	r.rotWord(a);
//	gettimeofday(&t2, 0);
/*	long mtime, seconds, useconds;
	seconds = t2.tv_sec - t1.tv_sec;
	useconds = t2.tv_usec - t1.tv_usec;
	mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	printf("%ld microseconds\n", mtime);
	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);*/
//	printf("%d\n", _sbox[0]);
/*	unsigned char bk_round1 [4][4] = {
		{ 0x19, 0xa0, 0x9a, 0xe9 },
		{ 0x3d, 0xf4, 0xc6, 0xf8 },
		{ 0xe3, 0xe2, 0x8d, 0x48 },
		{ 0xbe, 0x2b, 0x2a, 0x08 }
	};
	unsigned char bk_round0 [4][4] = {
		{ 0x32, 0x88, 0x31, 0xe0 },
		{ 0x43, 0x5a, 0x31, 0x37 },
		{ 0xf6, 0x30, 0x98, 0x07 },
		{ 0xa8, 0x8d, 0xa2, 0x34 }
	};
	unsigned char ck [4][4] = {
    		kit.run(*pWindow);
  	}	


//	Rijndael r(Rijndael::K128, Rijndael::B128);
//	timeval t1, t2;
/*	char input[1024];
	char ch[Rijndael::K128/8];
	unsigned char uch[Rijndael::K128/8];
	signed char sch[Rijndael::K128/8];*/
//	unsigned char a[5] = "abcd";
//	if (fgets(input, 16+1, stdin)){
//		if (sscanf(input, "%s", uch) == 1){
			//printf("%d\n", a[0]);
//		}
//	}
//	printf("%d\n", a);
//	gettimeofday(&t1, 0);
//	r.rotWord(a);
//	gettimeofday(&t2, 0);
/*	long mtime, seconds, useconds;
	seconds = t2.tv_sec - t1.tv_sec;
	useconds = t2.tv_usec - t1.tv_usec;
	mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
	printf("%ld microseconds\n", mtime);
	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);*/
//	printf("%d\n", _sbox[0]);
/*	unsigned char bk_round1 [4][4] = {
		{ 0x19, 0xa0, 0x9a, 0xe9 },
		{ 0x3d, 0xf4, 0xc6, 0xf8 },
		{ 0xe3, 0xe2, 0x8d, 0x48 },
		{ 0xbe, 0x2b, 0x2a, 0x08 }
	};
	unsigned char bk_round0 [4][4] = {
		{ 0x32, 0x88, 0x31, 0xe0 },
		{ 0x43, 0x5a, 0x31, 0x37 },
		{ 0xf6, 0x30, 0x98, 0x07 },
		{ 0xa8, 0x8d, 0xa2, 0x34 }
	};
	unsigned char ck [4][4] = {
		{ 0x2b, 0x7e, 0x15, 0x16 },
		{ 0x28, 0xae, 0xd2, 0xa6 },
		{ 0xab, 0xf7, 0x15, 0x88 },
		{ 0x09, 0xcf, 0x4f, 0x3c }
	};
	unsigned char bk [4][4] = {
		{ 0x00, 0x44, 0x88, 0xcc },
		{ 0x11, 0x55, 0x99, 0xdd },
		{ 0x22, 0x66, 0xaa, 0xee },
		{ 0x33, 0x77, 0xbb, 0xff }
	};
	unsigned char ck_1 [4][4] = {
		{ 0x00, 0x01, 0x02, 0x03 },
		{ 0x04, 0x05, 0x06, 0x07 },
		{ 0x08, 0x09, 0x0a, 0x0b },
		{ 0x0c, 0x0d, 0x0e, 0x0f }
	};
	unsigned char ck [6][4] = {
		{ 0x8e, 0x73, 0xb0, 0xf7 },
		{ 0xda, 0x0e, 0x64, 0x52 },
		{ 0xc8, 0x10, 0xf3, 0x2b },
		{ 0x80, 0x90, 0x79, 0xe5 },
		{ 0x62, 0xf8, 0xea, 0xd2 },
		{ 0x52, 0x2c, 0x6b, 0x7b }
	};*/

//	unsigned char ckoo[25] = "012345678901234567890123";
//	unsigned char bkoo[17] = "Texto para teste";
	// vector to block -> by column and by line
	// vector to key -> by line and by column
/*	unsigned char** ck1 = new unsigned char* [4];
//	unsigned char** bk1 = new unsigned char* [6];
	for (int i = 0; i < 4; i++){	
		ck1[i] = new unsigned char[4];	
		//bk1[i] = new unsigned char[4];
	}
*/		
/*	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			ck1[i][j] = ck[i][j];
//			bk1[i][j] = bk[i][j];
		}
	}*/

//	unsigned char ck192h[49] = "000102030405060708090a0b0c0d0e0f1011121314151617";
//	unsigned char ck256h[65] = "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f";
//	unsigned char ck256h[65] = "603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4";
//	unsigned char ck192h[49] = "8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b";
//	unsigned char ck192[25];
//	unsigned char ck256[33];
//	hexStringToCharString(ck256h, 64, ck256);
	//for (int i = 0; i < 24; i++)	printf("%x ", ck192[i]);
	//printf("\n");
//	unsigned char bk128h[33] = "00112233445566778899aabbccddeeff";
//	unsigned char bk128hc[33] = "8ea2b7ca516745bfeafc49904b496089";
//	unsigned char bk128[17];
//	hexStringToCharString(bk128h, 32, bk128);
//	gettimeofday(&t1, 0);
//	r.makeKey(&ck_demo[0][0]);
//	r.encrypt(bk128);
//	r.decrypt(bk128);
//	gettimeofday(&t2, 0);
//	for (int i = 0; i < 16; i++)	printf("%x ", bk128[i]);
//	printf("\n");

/*	gettimeofday(&t1, 0);
	r.makeKey(ckoo);	
	printf("%s\n", bkoo);
	r.encrypt(bkoo);
	printf("%s\n", bkoo);
	r.decrypt(bkoo);
	printf("%s\n", bkoo);*/
//	r.decrypt(bk1);*/
//	gettimeofday(&t2, 0);
	//printf("aqui\n");fflush(stdout);
	//printf("%s\n", ckoo);
//	printf("%ld %ld\n", t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
/*	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%x ", ck_1[i][j]);
		}
		printf("\n");
	}*/
/*	for (int i = 0; i < 4; i++){
//		delete[] bk1[i];
		delete[] ck1[i];
	}
//	delete[] bk1;
	delete[] ck1;*/
//	unsigned char a[1] = {0xbf};
/*	a[0] = a[0] << 1;		mult por 2
	a[0] ^= 0x1b;*/ 
	
//mult por 3
/*	a[0] = (a[0] << 1) ^ a[0];
	a[0] ^= 0x1b;*/
//	printf("%x\n", a[0]);
	return EXIT_SUCCESS;
}

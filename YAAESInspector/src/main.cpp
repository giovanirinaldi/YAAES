#include <QApplication>
#include <QDesktopWidget>
#include "ui/mainwindowimpl.h"
//
int main(int argc, char ** argv)
{
        QApplication app( argc, argv );        
        MainWindowImpl win;
        QDesktopWidget *desktop = QApplication::desktop();

        int WIDTH = win.size().width();
        int HEIGHT = win.size().height();
        int screenWidth = desktop->width();
        int screenHeight = desktop->height();
        int x = (screenWidth - WIDTH) / 2;
        int y = (screenHeight - HEIGHT) / 2;
        win.move( x, y );
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}

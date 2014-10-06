#include <QApplication>
#include <QtCore>
#include <QObject>
#include <QWidget>
#include <trafficlight.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
    TrafficLight trafficLight;
    trafficLight.show();

	return app.exec();
}

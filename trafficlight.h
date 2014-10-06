#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QtGui>
#include <QWidget>
#include <QString>

class TrafficLight : public QWidget
{
	Q_OBJECT
public:
	explicit TrafficLight(QWidget *parent = 0);
protected:
	void paintEvent(QPaintEvent *event);
	int state = 0; //0 - red, 1 - yellow, 2 - green
	int s[3] = {40, 7, 40}; //40, 7, 40
	bool greenoff = 0, back = 0;
signals:

public slots:
	void update();
public:
	void resetCounter();
};

#endif // TRAFFICLIGHT_H

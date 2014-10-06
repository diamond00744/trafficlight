#include "trafficlight.h"
#include <QtGui>

TrafficLight::TrafficLight(QWidget *parent) :
	QWidget(parent)
{
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(500);
    setWindowTitle(/*tr*/("Traffic Light"));
	resize(200, 600);
}

void TrafficLight::resetCounter() {
	s[0]=40; s[1]=7; s[2]=40;
}

void TrafficLight::update() {
	s[state]--;
	if (!s[state]) {
		if (back)
			state--;
		else
			state++;
		if ((state<0)||(state>2)) {
			back = !back;
			state=1;
		}
		resetCounter();
	}
	QWidget::update();
}

void TrafficLight::paintEvent(QPaintEvent*) {
	QColor offColor(0, 0, 0);
	QColor topColor(255, 0, 0);
	QColor middleColor(255, 200, 0);
	QColor bottomColor(0, 255, 0);

	int side = qMin(width(), height()/3);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	QFont font = painter.font();
	font.setPointSizeF(side/2);
    font.setFamily("LCDMono");
	font.setBold(1);
	painter.setFont(font);

	//painter.translate(width() / 2, height() / 2);
	painter.scale(side / 200.0, side / 200.0);

	painter.setPen(Qt::NoPen);
	painter.setBrush(offColor);
	painter.drawEllipse(0, 0, 200, 200);
	painter.drawEllipse(0, 200, 200, 200);
	painter.drawEllipse(0, 400, 200, 200);
	if (state == 0) {
		painter.setBrush(topColor);
		painter.setPen(topColor);
		painter.drawEllipse(0, 0, 200, 200);
		painter.drawText(QRectF(0, 250, 200, 100), Qt::AlignCenter, QString::number(s[0]/2));
	}
	if (state == 1) {
		if (!back) {
			painter.setBrush(topColor);
			painter.drawEllipse(0, 0, 200, 200);
		}
		painter.setBrush(middleColor);
		painter.drawEllipse(0, 200, 200, 200);
	}
	if (state == 2) {
		painter.setBrush(bottomColor);
		painter.setPen(bottomColor);
		if (s[2]<7)
			if (greenoff=!greenoff)
				painter.setBrush(offColor);
		painter.drawEllipse(0, 400, 200, 200);
		painter.drawText(QRectF(0, 250, 200, 100), Qt::AlignCenter, QString::number(s[2]/2));
	}
}

#include <QGraphicsDropShadowEffect>
#include "cell.h"

Cell::Cell(int v): value(v)
{
    setAlignment(Qt::AlignCenter);
}

void Cell::draw()
{
    setText(QString::number(value));
    auto style = QString("Cell { background: %1; color: %2; font: bold; border-radius: 10px; font: 40pt; }");
    switch (value) {
    case 2: {
        setStyleSheet(style.arg("rgb(238,228,218)").arg("rgb(119,110,101)"));
        break;
    }
    case 4: {
        setStyleSheet(style.arg("rgb(237,224,200)").arg("rgb(119,110,101)"));
        break;
    }
    case 8: {
        setStyleSheet(style.arg("rgb(242,177,121)").arg("rgb(255,255,255)"));
        break;
    }
    case 16: {
        setStyleSheet(style.arg("rgb(245,150,100)").arg("rgb(255,255,255)"));
        break;
    }
    case 32: {
        setStyleSheet(style.arg("rgb(245,125,95)").arg("rgb(255,255,255)"));
        break;
    }
    case 64: {
        setStyleSheet(style.arg("rgb(245,95,60)").arg("rgb(255,255,255)"));
        break;
    }
    case 128: {
        setStyleSheet(style.arg("rgb(237,207,114)").arg("rgb(255,255,255)"));
        break;
    }
    case 256: {
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(20);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    case 512: {
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(30);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    case 1024: {
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(40);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    case 2048: {
        QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
        dse->setColor(Qt::yellow);
        dse->setBlurRadius(50);
        dse->setOffset(-1);
        setGraphicsEffect(dse);
        setStyleSheet(style.arg("rgb(237,204,97)").arg("rgb(255,255,255)"));
        break;
    }
    default: {
        setText("");
        setStyleSheet("Cell { background: rgb(204,192,179); border-radius: 10px; }");
    }
    }

}

#include "starsystemobject.hh"

QRectF starsystemobject::boundingRect() const {
    return QRectF(0, 0, starsystemsize_, starsystemsize_);
}



void starsystemobject::setSizeByPop(int population) {
    if (population <= 200000) {
        starsystemsize_ = 20;

    } else if (population <= 2000000){
        starsystemsize_ = 40;

    } else {
        starsystemsize_ = 60;
    }
}

int starsystemobject::getSize() {
    return starsystemsize_;
}

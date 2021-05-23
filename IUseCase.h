#ifndef USELESS_BOX_IUSECASE_H
#define USELESS_BOX_IUSECASE_H

class IUseCase {
public:
    virtual void run() = 0;

    virtual int cyclesFinished() = 0;
};

#endif //USELESS_BOX_IUSECASE_H

#ifndef FrameContainer_h
#define FrameContainer_h

#include <QFrame>


class FrameContainer 
    : public QFrame
{
public:
            FrameContainer (QWidget* parent = nullptr);
    virtual ~FrameContainer();
};


#endif // FrameContainer_h

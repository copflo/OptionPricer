#include "FrameContainer.h"


FrameContainer::FrameContainer(QWidget* parent)
    : QFrame(parent)
{
    setFrameShadow(QFrame::Raised);
    setFrameShape(QFrame::WinPanel);
    setLineWidth(1);
    setMidLineWidth(1);
}

FrameContainer::~FrameContainer()
{
}

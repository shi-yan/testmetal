#include "view_delegate.h"
#include <iostream>

MyMTKViewDelegate::MyMTKViewDelegate( MTL::Device* pDevice )
: MTK::ViewDelegate()
, _pRenderer( new Renderer( pDevice ) )
{
    std::cout << "view delegate" << std::endl;
}

MyMTKViewDelegate::~MyMTKViewDelegate()
{
    delete _pRenderer;
}



void MyMTKViewDelegate::drawInMTKView( MTK::View* pView )
{
    std::cout << "draw 2" << std::endl;
    _pRenderer->draw( pView );
}

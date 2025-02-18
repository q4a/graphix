#include "GXSurface.h"

void CGXSurface::Release()
{
	--m_uRefCount;
	if(!m_uRefCount)
	{
		m_pRender->destroyColorTarget(this);
	}
}

CGXSurface::~CGXSurface()
{
	mem_release(m_pSurface);
}

UINT CGXSurface::getWidth()
{
	return(m_uWidth);
}
UINT CGXSurface::getHeight()
{
	return(m_uHeight);
}
GXFORMAT CGXSurface::getFormat()
{
	return(m_format);
}

void CGXSurface::onDevLost()
{
	mem_release(m_pSurface);
}
void CGXSurface::onDevRst(UINT uScreenWidth, UINT uScreenHeight)
{
	if(m_bAutoResize)
	{
		m_uWidth = (UINT)((float)uScreenWidth * m_fSizeCoeffW);
		m_uHeight = (UINT)((float)uScreenHeight * m_fSizeCoeffH);

		if(m_uWidth < 1)
		{
			m_uWidth = 1;
		}
		if(m_uHeight < 1)
		{
			m_uHeight = 1;
		}
	}

	DX_CALL(m_pRender->getDXDevice()->CreateRenderTarget(m_uWidth, m_uHeight, m_pRender->getDXFormat(m_format), m_multisampleType, 0, FALSE, &m_pSurface, NULL));
}

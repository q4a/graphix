#include "GXIndexBuffer.h"

void CGXIndexBuffer::Release()
{
	--m_uRefCount;
	if(!m_uRefCount)
	{
		m_pRender->destroyIndexBuffer(this);
	}
}

bool CGXIndexBuffer::lock(void **ppData, GXBUFFERLOCK mode)
{
	assert(mode == GXBL_WRITE);
	assert(m_isLockable);

	if(!m_isLockable || mode != GXBL_WRITE)
	{
		return(false);
	}

	D3D11_MAPPED_SUBRESOURCE srs;

	if(!FAILED(DX_CALL(m_pRender->getDXDeviceContext()->Map(m_pBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &srs))))
	{
		m_wasReset = false;
		return(true);
	}
	return(false);
}

void CGXIndexBuffer::unlock()
{
	m_pRender->getDXDeviceContext()->Unmap(m_pBuffer, 0);
}

CGXIndexBuffer::~CGXIndexBuffer()
{
	mem_release(m_pBuffer);
}

bool CGXIndexBuffer::wasReset()
{
	return(m_wasReset);
}

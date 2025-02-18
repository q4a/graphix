#ifndef _IDSRindexBufferOgl_H_
#define _IDSRindexBufferOgl_H_

#include "GXContext.h"


class CGXIndexBuffer: public IGXIndexBuffer
{
	friend class CGXContext;
	friend class CGXDevice;

	CGXIndexBuffer(CGXDevice *pRender):
		m_pRender(pRender)
	{
	}

	CGXDevice *m_pRender;
	GLuint m_pBuffer;
	bool m_wasReset = true;
	UINT m_uSize;

public:
	void Release();

	bool lock(void** ppData, GXBUFFERLOCK mode) override;
	void unlock() override;

	bool wasReset() override;
};

#endif

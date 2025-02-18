
/*****************************************************
Copyright © DogmaNet Team, 2019
Site: dogmanet.ru
See the license in LICENSE
*****************************************************/

//! \gtodo добавить common в репозиторий

/*! \gtodo пересмотреть методы IGXContext::create ... Shader методы повторяются аж 4 раза, как и комментарии
был вариант создать метод
virtual IGXShaderBase* createShader(GX_SHADER_TYPE type, const char * szFile, GXMacro *pDefs = NULL) = 0;
который бы внутри создавал конкретный шейдер, а возвращал базовый,
нормальный вариант но ошибку несоответсвия типов не получить на этапе компиляции
*/

/*! \gtodo пересмотреть методы setTexture, так как они устанавливаются для типов шейдеров и повторяются 3 раза
есть вариант передавать аргументом тип шейдера
*/

/*! \gtodo добавить возможность для фильтрации текстур в других шейдерах
в метод setSamplerState отправлять тип шейдера для применения к нему фильтрации
*/

/*! @gtodo разобраться с именованием GX и GX_, структуры имен одинаковы у дефайнов, енумов и структур
*/

#ifndef __GRAPHIX_H
#define __GRAPHIX_H

#include <common/types.h>
#include <common/Math.h>

/* Enable High Performance Graphics while using Integrated Graphics. */
#define GX_ENABLE_HIGH_PERFORMANCE_DUAL_GPU() C {                                     \
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;        /* Nvidia */ \
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;  /* AMD    */ \
}

#include "GX/ILogger.h"
#include "GX/color.h"
#include "GX/ibase.h"
#include "GX/textures.h"
#include "GX/surfaces.h"
#include "GX/states.h"
#include "GX/shaders.h"
#include "GX/adapter_stats.h"
#include "GX/buffers.h"
#include "GX/device.h"

#endif

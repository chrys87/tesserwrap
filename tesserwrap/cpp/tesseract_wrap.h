#include <stdint.h>
#include "tesseract_ext.h"

#ifdef __cplusplus
#  define TR_C_START           extern "C" {
#  define TR_C_END             }
#else
#  define TR_C_START
#  define TR_C_END
#endif
#define TESSERWRAP_CAPI __attribute__ ((visibility("default")))

TR_C_START

enum PILImageFormat
{
L = 0, RGB=3, RGBA=4
};


typedef TessBaseAPIExt* TessH;

TESSERWRAP_CAPI TessH Tesserwrap_Init(const char *datadir, const char *lang);
TESSERWRAP_CAPI void Tesserwrap_Destroy(TessH tesserwrap);
TESSERWRAP_CAPI void Tesserwrap_GetRectangle(TessH tesserwrap,
    uint64_t *left, uint64_t *top,
    uint64_t *width, uint64_t *height);
TESSERWRAP_CAPI void Tesserwrap_SetRecangle(TessH tesserwrap,
    uint64_t *left, uint64_t *top,
    uint64_t *width, uint64_t *height);
TESSERWRAP_CAPI void Tesserwrap_SetImage(TessH tesserwrap,
    const unsigned char *picture, uint64_t size, uint64_t width, uint64_t height);
TESSERWRAP_CAPI void Tesserwrap_SetPageSegMode(TessH tesserwrap,
    tesseract::PageSegMode pageseg);
TESSERWRAP_CAPI tesseract::PageSegMode Tesserwrap_GetPageSegMode(TessH tesserwrap);

TR_C_END

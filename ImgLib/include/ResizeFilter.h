//
// Created by Administrator on 2023/11/23.
//

#ifndef IMGTEST_RESIZEHELPER_H
#define IMGTEST_RESIZEHELPER_H
#include "Image.h"
class ReszieFilter {
private:
    bool HUpScaleImage_4x(BYTE *pInLine, BYTE *pOutLine, int nInWidth, int nOutWidth);

    bool
    VUpScaleImage_4x(BYTE *pInLine[], BYTE *pOutLine1, BYTE *pOutLine2, BYTE *pOutLine3, BYTE *pOutLine4, int Width);

protected:

public:
    ReszieFilter();

    ~ReszieFilter();

    bool DownScaleImage_4x(GrayImageBYTE *pInImge, GrayImageBYTE *pOutImage, int nInWidth, int nInHeight, int nInStride = 0);

    bool DownScaleImage_2x(GrayImageBYTE *pInImge, GrayImageBYTE *pOutImage, int nInWidth, int nInHeight, int nInStride = 0);

    bool UpScaleImage_4x(GrayImageBYTE *pInImge, GrayImageBYTE *pOutImage, int nInWidth, int nInHeight, int nInStride = 0);

    bool UpScaleImage_2x(GrayImageBYTE *pInImge, GrayImageBYTE *pOutImage, int nInWidth, int nInHeight, int nInStride = 0);

    bool DownScale(GrayImageBYTE *pInImge, GrayImageBYTE *pOutImage);

    bool UpScale(GrayImageBYTE *pInImge, GrayImageBYTE *pOutImage);

    bool Process(GrayImageBYTE *pInImge, GrayImageBYTE *pOutImage);

};


#endif //IMGTEST_RESIZEHELPER_H

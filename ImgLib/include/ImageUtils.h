//
// Created by Administrator on 2023/10/26.
//

#ifndef IMGLIB_IMAGEUTILS_H
#define IMGLIB_IMAGEUTILS_H

#include "Image.h"
#include <libyuv/convert.h>

class ImageUtils {
public:
    bool nv2gray(YUV420ImageBYTE *pInImage, GrayImageBYTE *pOutImage);

    //// NV to rgb &yuv
    bool nv12torgb(YUV420ImageBYTE *pInImage, RGBImageBYTE *pOutImage);

    bool nv21torgb(YUV420ImageBYTE *pInImage, RGBImageBYTE *pOutImage);

    bool rgb2nv12(RGBImageBYTE *pInImage, YUV420ImageBYTE *pOutImage);

    bool rgb2nv21(RGBImageBYTE *pInImage, YUV420ImageBYTE *pOutImage);


    bool nv12toyuv(YUV420ImageBYTE *pInImage, YUVImageBYTE *pOutImage);

    bool nv21toyuv(YUV420ImageBYTE *pInImage, YUV420ImageBYTE *pOutImage);

    //// ResizeFilter
    bool ReSize(GrayImageBYTE *pInImage, GrayImageBYTE *pOutImage);

    bool ReSize(YUV420ImageBYTE *pInImage, YUV420ImageBYTE *pOutImage);

    bool ReSize(RGBImageBYTE *pInImage, RGBImageBYTE *pOutImage);

    bool ReSize(RGBAImageBYTE *pInImage, RGBAImageBYTE *pOutImage);

    //// Crop
    bool Crop(GrayImageBYTE *pInImage, Rect inRect, GrayImageBYTE *pOutImage);

    bool Crop(GrayImageBYTE *pInImage, Rect inRect, GrayImageBYTE *pOutImage, Rect outRect);

    bool Crop(YUV420ImageBYTE *pInImage, Rect inRect, YUV420ImageBYTE *pOutImage);

    bool Crop(YUV420ImageBYTE *pInImage, Rect inRect, YUV420ImageBYTE *pOutImage, Rect outRect);

};


#endif //IMGLIB_IMAGEUTILS_H

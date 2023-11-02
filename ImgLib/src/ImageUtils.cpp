//
// Created by Administrator on 2023/10/26.
//

#include "ImageUtils.h"

bool ImageUtils::nv12toyuv(YUV420ImageBYTE *pInImage, YUVImageBYTE *pOutImage) {
//    libyuv::ScalePlane(pInImage->GetPtr(), pInImage->GetStride(), pInImage->GetWidth(), pInImage->GetHeight(),
//                       pOutImage->GetPtr(), pOutImage->GetStride(), pOutImage->GetStride(), pOutImage->GetHeight(),
//                       libyuv::kFilterLinear);
    YUV420ImageBYTE tmp(*pInImage);
    libyuv::NV12ToI420(pInImage->GetPtr(), pInImage->GetStride(), pInImage->GetUVPtr(), pInImage->GetStride(),
                       tmp.GetPtr(), tmp.GetStride(),
                       tmp.GetUVPtr(), tmp.GetStride() >> 1,
                       tmp.GetUVPtr() + (tmp.GetStride() * tmp.GetHeight() >> 2), tmp.GetStride() >> 1,
                       tmp.GetWidth(), tmp.GetHeight());
    tmp.SaveBuffer("tmp.yuv");

//    libyuv::ScalePlane(tmp.GetPtr(), tmp.GetStride(), tmp.GetWidth(), tmp.GetHeight(),
//                       pOutImage->GetPtr(), pOutImage->GetStride(), pOutImage->GetWidth(), pOutImage->GetHeight(),
//                       libyuv::kFilterBilinear);
//    libyuv::ScalePlane(tmp.GetUVPtr(), tmp.GetStride()>>1, tmp.GetWidth()>>1, tmp.GetHeight() >> 1,
//                       pOutImage->GetPtr() +pOutImage->GetHeight() * pOutImage->GetStride(), pOutImage->GetStride(), pOutImage->GetWidth(),
//                       pOutImage->GetHeight(),
//                       libyuv::kFilterBilinear);
    libyuv::I420ToI444(tmp.GetPtr(), tmp.GetStride(),
                       tmp.GetUVPtr(), tmp.GetStride() >> 1,
                       tmp.GetUVPtr() + (tmp.GetStride() * tmp.GetHeight() >> 2), tmp.GetStride() >> 1,
                       pOutImage->GetPtr(), pOutImage->GetStride(),
                       pOutImage->GetPtr() + pOutImage->GetHeight() * pOutImage->GetStride(), pOutImage->GetStride(),
                       pOutImage->GetPtr() + pOutImage->GetHeight() * pOutImage->GetStride() * 2,
                       pOutImage->GetStride(),
                       pOutImage->GetWidth(), pOutImage->GetHeight());
    return true;
}

bool ImageUtils::nv12Rotate90(YUV420ImageBYTE *pInImage, YUV420ImageBYTE *pOutImage) {
    libyuv::RotatePlane90(pInImage->GetPtr(), pInImage->GetStride(),
                          pOutImage->GetPtr(), pOutImage->GetStride(),
                          pInImage->GetWidth(), pInImage->GetHeight());

    GrayImageBYTE U(pInImage->GetHeight() >> 1,pInImage->GetWidth() >> 1);
    GrayImageBYTE V(pInImage->GetHeight() >> 1,pInImage->GetWidth() >> 1);
    libyuv::SplitRotateUV90(pInImage->GetUVPtr(), pInImage->GetStride(),
                            U.GetPtr(), U.GetStride(),
                            V.GetPtr(), V.GetStride(),
                            pInImage->GetWidth() >> 1,pInImage->GetHeight() >> 1);
//    U.SaveBuffer("U.yuv");
    libyuv::MergeUVPlane(U.GetPtr(), U.GetStride(),
                         V.GetPtr(), V.GetStride(),
                         pOutImage->GetUVPtr(), pOutImage->GetStride(),
                         pOutImage->GetWidth() >> 1, pOutImage->GetHeight() >> 1);
    return false;
}

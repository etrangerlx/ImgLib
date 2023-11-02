//
// Created by Administrator on 2023/7/5.
//

#ifndef OPENGL_TEST_IMAGEBYTE_H
#define OPENGL_TEST_IMAGEBYTE_H

#include "SimpleType.h"

class GrayImageBYTE : public Mat_<BYTE> {
public:
    GrayImageBYTE();

    GrayImageBYTE(size_t Width, size_t Height);

    GrayImageBYTE(size_t Width, size_t Stride, size_t Height);

    explicit GrayImageBYTE(const GrayImageBYTE &obj);

    GrayImageBYTE &operator=(const GrayImageBYTE &obj);
};

class YUV420ImageBYTE : public Mat_<BYTE> {
public:
    YUV420ImageBYTE();

    YUV420ImageBYTE(size_t Width, size_t Height);

    YUV420ImageBYTE(size_t Width, size_t Stride, size_t Height);

    explicit YUV420ImageBYTE(const YUV420ImageBYTE &obj);

    YUV420ImageBYTE &operator=(const YUV420ImageBYTE &obj);

    BYTE *GetUVPtr();
};

class RGBImageBYTE : public Mat_<BYTE> {
public:
    RGBImageBYTE();

    RGBImageBYTE(size_t Width, size_t Height);

    RGBImageBYTE(size_t Width, size_t Stride, size_t Height);

    explicit RGBImageBYTE(const RGBImageBYTE &obj);

    RGBImageBYTE &operator=(const RGBImageBYTE &obj);

    void SaveImageBYTE(const char *filename);

    void LoadImageBYTE(const char *filename);

};

typedef RGBImageBYTE YUVImageBYTE;

class RGBAImageBYTE : public Mat_<BYTE> {
public:
    RGBAImageBYTE();

    RGBAImageBYTE(size_t Width, size_t Height);

    RGBAImageBYTE(size_t Width, size_t Stride, size_t Height);

    explicit RGBAImageBYTE(const RGBAImageBYTE &obj);

    RGBAImageBYTE &operator=(const RGBAImageBYTE &obj);

    void SaveImageBYTE(const char *filename);

    void LoadImageBYTE(const char *filename);

};


#endif //OPENGL_TEST_IMAGEBYTE_H

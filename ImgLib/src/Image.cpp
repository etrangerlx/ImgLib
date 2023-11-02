//
// Created by Administrator on 2023/7/5.
//
#include "Image.h"
#include<iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stb_image_write.h>

GrayImageBYTE::GrayImageBYTE() : Mat_<BYTE>() {
}

GrayImageBYTE::GrayImageBYTE(size_t Width, size_t Height) : Mat_<BYTE>(Width, Width, Height, 1) {
}

GrayImageBYTE::GrayImageBYTE(size_t Width, size_t Stride, size_t Height) : Mat_(Width, Stride, Height, 1) {

}

GrayImageBYTE::GrayImageBYTE(const GrayImageBYTE &obj) {
    ClearBuffer();
    int res = CreateBuffer(obj.GetWidth(), obj.GetStride(), obj.GetHeight(), obj.GetDim());
    if (res) {
        memcpy(GetPtr(), obj.GetPtr(), obj.GetBufferSizeByte());
    } else {
        printf("GrayImageBYTE Copy error!\n");
    }
}

GrayImageBYTE &GrayImageBYTE::operator=(const GrayImageBYTE &obj) {
    if (this == &obj) {
        return *this;
    }
    GrayImageBYTE m(obj);
    memcpy(GetPtr(), m.GetPtr(), m.GetBufferSizeByte());
    return *this;
}

YUV420ImageBYTE::YUV420ImageBYTE() : Mat_<BYTE>() {

}

YUV420ImageBYTE::YUV420ImageBYTE(size_t Width, size_t Height) : Mat_<BYTE>(Width, Height, 2) {

}

YUV420ImageBYTE::YUV420ImageBYTE(size_t Width, size_t Stride, size_t Height) : Mat_(Width, Stride, Height, 3) {

}

YUV420ImageBYTE::YUV420ImageBYTE(const YUV420ImageBYTE &obj) {
    ClearBuffer();
    int res = CreateBuffer(obj.GetWidth(), obj.GetStride(), obj.GetHeight(), obj.GetDim());
    if (res) {
        memcpy(GetPtr(), obj.GetPtr(), obj.GetBufferSizeByte());
    } else {
        printf("YUV420ImageBYTE Copy Error\n");
    }

}

YUV420ImageBYTE &YUV420ImageBYTE::operator=(const YUV420ImageBYTE &obj) {
    if (this == &obj) {
        return *this;
    }
    YUV420ImageBYTE m(obj);
    memcpy(GetPtr(), m.GetPtr(), m.GetBufferSizeByte());
    return *this;
}

BYTE *YUV420ImageBYTE::GetUVPtr() {
    return GetPtr() + GetStride() * GetHeight();
}


RGBImageBYTE::RGBImageBYTE() : Mat_<BYTE>() {

}

RGBImageBYTE::RGBImageBYTE(size_t Width, size_t Height) : Mat_<BYTE>(Width, Height, 3) {

}

RGBImageBYTE::RGBImageBYTE(const RGBImageBYTE &obj) {
    ClearBuffer();
    int res = CreateBuffer(obj.GetWidth(), obj.GetStride(), obj.GetHeight(), obj.GetDim());
    if (res) {
        memcpy(GetPtr(), obj.GetPtr(), obj.GetBufferSizeByte());
    } else {
        printf("RGBImageBYTE Copy error\n");
    }

}

RGBImageBYTE &RGBImageBYTE::operator=(const RGBImageBYTE &obj) {
    if (this == &obj) {
        return *this;
    }
    int res = CreateBuffer(obj.GetWidth(), obj.GetStride(), obj.GetHeight(), obj.GetDim());
    if (res) {
        memcpy(GetPtr(), obj.GetPtr(), obj.GetBufferSizeByte());
    }
    return *this;
}

RGBImageBYTE::RGBImageBYTE(size_t Width, size_t Stride, size_t Height) : Mat_(Width, Stride, Height, 3) {

}

void RGBImageBYTE::LoadImageBYTE(const char *filename) {
    int iw, ih, n;
// 加载图片获取宽、高、颜色通道信息
    unsigned char *idata = stbi_load(filename, &iw, &ih, &n, 0);
    CreateBuffer(iw, iw, ih, n);
    memcpy(GetPtr(), idata, GetBufferSizeByte());
    stbi_image_free(idata);
    idata = nullptr;
}

void RGBImageBYTE::SaveImageBYTE(const char *filename) {
    std::string str_file(filename);
    char path[1024];
    size_t pos = str_file.find(".");
    std::string sufix = std::string(str_file, 0, pos);
    std::string postfix = std::string(str_file, pos, str_file.size() - pos);
    sprintf(path, "%s_%dx%dx%d_%d.%s", str_file.c_str(),
            GetWidth(), GetStride(), GetHeight(), GetDim(),
            postfix.c_str());
    stbi_write_bmp(path, GetWidth(), GetHeight(), GetDim(), GetPtr());
}

RGBAImageBYTE::RGBAImageBYTE() : Mat_<BYTE>() {

}

RGBAImageBYTE::RGBAImageBYTE(size_t Width, size_t Height) : Mat_<BYTE>(Width, Width, Height, 4) {

}

RGBAImageBYTE::RGBAImageBYTE(size_t Width, size_t Stride, size_t Height) : Mat_(Width, Stride, Height, 4) {

}

RGBAImageBYTE::RGBAImageBYTE(const RGBAImageBYTE &obj) {
    ClearBuffer();
    CreateBuffer(obj.GetWidth(), obj.GetStride(), obj.GetHeight(), obj.GetDim());
    memcpy(GetPtr(), obj.GetPtr(), obj.GetStride() * obj.GetHeight() * obj.GetDim() * sizeof(BYTE));
}

RGBAImageBYTE &RGBAImageBYTE::operator=(const RGBAImageBYTE &obj) {
    if (this == &obj) {
        return *this;
    }
    int res = CreateBuffer(obj.GetWidth(), obj.GetStride(), obj.GetHeight(), obj.GetDim());
    if (res) {
        memcpy(GetPtr(), obj.GetPtr(), obj.GetBufferSizeByte());
    }
    return *this;
}

void RGBAImageBYTE::SaveImageBYTE(const char *filename) {
    int iw, ih, n;
// 加载图片获取宽、高、颜色通道信息
    unsigned char *idata = stbi_load(filename, &iw, &ih, &n, 0);
    CreateBuffer(iw, iw, ih, n);
    memcpy(GetPtr(), idata, GetBufferSizeByte());
    stbi_image_free(idata);
    idata = nullptr;
}

void RGBAImageBYTE::LoadImageBYTE(const char *filename) {
    std::string str_file(filename);
    char path[1024];
    size_t pos = str_file.find(".");
    std::string sufix = std::string(str_file, 0, pos);
    std::string postfix = std::string(str_file, pos, str_file.size() - pos);
    sprintf(path, "%s_%dx%dx%d_%d.%s", str_file.c_str(),
            GetWidth(), GetStride(), GetHeight(), GetDim(),
            postfix.c_str());
    stbi_write_bmp(path, GetWidth(), GetHeight(), GetDim(), GetPtr());
}



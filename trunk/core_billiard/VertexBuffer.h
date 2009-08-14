#pragma once
namespace my_render {


INTERFACE_ VertexBuffer {
public:
    virtual void appendNormal_Array( float * normals_3floatsForEach ) = 0;
    virtual void appendTexCoord2D_Array( float * texCoords_2floatsForEach ) = 0;

    virtual size_t getNumberOfVertex() = 0;
    virtual bool hasNormal() = 0;
    virtual size_t getNumberOfTexCoords() = 0;

public: virtual ~VertexBuffer() {}
};


}
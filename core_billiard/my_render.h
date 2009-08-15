#pragma once
#include "stdafx.h"

namespace my_render {
    using namespace std;

    class ApplicationWindow;
    class MouseEventListener;
    class KeyboardEventListener;
    class NullMouseEventListener;
    class NullKeyboardEventListener;

    class SurfaceLockedRect;
    class Surface;
    class Render;
    class RenderEventListener;
    class NullRender;
    class NullRenderEventListener;

    class Shader;
    class Texture;
    class VertexShader;
    class PixelShader;
    class EffectShader;
    class ShaderVariableWriter;
    class RenderEffectShader;

    class VertexBuffer;
    class IndexBuffer;
    class RenderBufferFactory;
    class NullRenderBufferFactory;

    class Scene;

    class Base;
    class Node;
    class Camera;

    class Factory;
    class NodeFactory;
    class GeometryFactory;
    class Instance;
    class InstanceResolver;

    class Geometry;
    class GeometryMesh;
    class GeometryMeshPrimitive;


    MY_SMART_PTR( ApplicationWindow );
    MY_SMART_PTR( MouseEventListener );
    MY_SMART_PTR( KeyboardEventListener );
    MY_SMART_PTR( NullMouseEventListener );
    MY_SMART_PTR( NullKeyboardEventListener );
    MY_SMART_PTR( SurfaceLockedRect );
    MY_SMART_PTR( Surface );
    MY_SMART_PTR( Render );
    MY_SMART_PTR( RenderEventListener );
    MY_SMART_PTR( NullRender );
    MY_SMART_PTR( NullRenderEventListener );
    MY_SMART_PTR( VertexBuffer );
    MY_SMART_PTR( IndexBuffer );
    MY_SMART_PTR( Texture );
    MY_SMART_PTR( Shader );
    MY_SMART_PTR( ShaderVariableWriter );
    MY_SMART_PTR( VertexShader );
    MY_SMART_PTR( PixelShader );
    MY_SMART_PTR( RenderEffectShader );
    MY_SMART_PTR( EffectShader );
    MY_SMART_PTR( RenderBufferFactory );
    MY_SMART_PTR( NullRenderBufferFactory );
    MY_SMART_PTR( Scene );
    MY_SMART_PTR( Base );
    MY_SMART_PTR( Node );
    MY_SMART_PTR( Camera );
    MY_SMART_PTR( Factory );
    MY_SMART_PTR( NodeFactory );
    MY_SMART_PTR( GeometryFactory );
    MY_SMART_PTR( Instance );
    MY_SMART_PTR( InstanceResolver );
    MY_SMART_PTR( Geometry );
    MY_SMART_PTR( GeometryMesh );
    MY_SMART_PTR( GeometryMeshPrimitive );
}

#include "ApplicationWindow.h"
#include "MouseEventListener.h"
#include "KeyboardEventListener.h"
#include "NullMouseEventListener.hpp"
#include "NullKeyboardEventListener.hpp"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "RenderBufferFactory.h"
#include "NullRenderBufferFactory.hpp"

#include "ShaderVariableWriter.h"
#include "Texture.h"
#include "Shader.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "RenderEffectShader.h"
#include "EffectShader.h"

#include "RenderEventListener.h"
#include "NullRenderEventListener.hpp"
#include "SurfaceLockedRect.h"
#include "Surface.h"
#include "Render.h"
#include "NullRender.hpp"
#include "Scene.h"

#include "Base.h"
#include "Node.h"
#include "Camera.h"
#include "Pause.h"

#include "Factory.h"
#include "NodeFactory.h"
#include "GeometryFactory.h"
#include "Instance.h"
#include "InstanceResolver.h"

#include "Geometry.h"
#include "GeometryMesh.h"
#include "GeometryMeshPrimitive.h"